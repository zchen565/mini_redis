#include <signal.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <sys/resource.h>
#include "Server.h"
#include "ListenSocket.h"
#include "ClientSocket.h"
#include "StreamSocket.h"
#include "NetThreadPool.h"
#include "Timer.h"
#include "Log/Logger.h"

using Internal::NetThreadPool;


void Server::IntHandler(int signum)
{
    if (Server::Instance() != NULL)
        Server::Instance()->Terminate();
}

void Server::HupHandler(int signum)
{
    if (Server::Instance() != NULL)
        Server::Instance()->reloadCfg_ = true;
}

Server* Server::sinstance_ = nullptr;

std::set<int> Server::slistenSocks_;

Server::Server() : bTerminate_(false), reloadCfg_(false)
{
    if (sinstance_ == NULL)
        sinstance_ = this;
    else
        ::abort();
}

Server::~Server()
{
    sinstance_ = NULL;
}

bool Server::_RunLogic()
{
    return tasks_.DoMsgParse();
}

bool Server::TCPBind(const SocketAddr& addr, int tag)
{
    using Internal::ListenSocket;

    auto s(std::make_shared<ListenSocket>(tag));

    if (s->Bind(addr))
    {
        slistenSocks_.insert(s->GetSocket());
        return true;
    }

    return false;
}


void Server::TCPReconnect(const SocketAddr& peer, int tag)
{
    INF << __FUNCTION__ << peer.GetIP();

    Timer* pTimer = TimerManager::Instance().CreateTimer();
    pTimer->Init(2 * 1000, 1);
    pTimer->SetCallback([&, tag, peer]() {
        USR << "OnTimer reconnect to " << peer.GetIP() << ":" << peer.GetPort();
        Server::Instance()->TCPConnect(peer, [=]() { Server::Instance()->TCPReconnect(peer, tag); }, tag);
    });


    TimerManager::Instance().AsyncAddTimer(pTimer);
}

void Server::TCPConnect(const SocketAddr& peer, int tag)
{
    _TCPConnect(peer, nullptr, tag);
}

void Server::TCPConnect(const SocketAddr& peer, const std::function<void ()>& cb, int tag)
{
    _TCPConnect(peer, &cb, tag);
}

void Server::_TCPConnect(const SocketAddr& peer, const std::function<void ()>* cb, int tag)
{
    auto client(std::make_shared<ClientSocket>(tag));
    if (cb)
        client->SetFailCallback(*cb);

    client->Connect(peer);
}

void Server::MainLoop(bool daemon)
{
    struct sigaction sig;
    ::memset(&sig, 0, sizeof(sig));
    sig.sa_handler = &Server::IntHandler;
    sigaction(SIGINT, &sig, NULL);
    sigaction(SIGQUIT, &sig, NULL);
    sigaction(SIGABRT, &sig, NULL);
    sigaction(SIGTERM, &sig, NULL);
    sig.sa_handler =  &Server::HupHandler;
    sigaction(SIGHUP, &sig, NULL);

    sig.sa_handler = SIG_IGN;
    sigaction(SIGPIPE, &sig, NULL);

    ::pthread_atfork(nullptr, nullptr, AtForkHandler);

    ::srand(static_cast<unsigned int>(time(NULL)));
    ::srandom(static_cast<unsigned int>(time(NULL)));

    // daemon must be first, before descriptor open, threads create
    if (daemon)
    {
        (void)::daemon(1, 0);
    }

    if (NetThreadPool::Instance().StartAllThreads() &&
        _Init() &&
        LogManager::Instance().StartLog())
    {
        while (!bTerminate_)
        {
            if (reloadCfg_)
            {
                ReloadConfig();
                reloadCfg_ = false;
            }

            if (!_RunLogic())
                std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
    }

    tasks_.Clear();
    _Recycle();
    NetThreadPool::Instance().StopAllThreads();
    LogManager::Instance().StopLog();

    ThreadPool::Instance().JoinAll();
}


std::shared_ptr<StreamSocket> Server::_OnNewConnection(int tcpsock, int tag)
{
    WRN << "implement your _OnNewConnection, now close socket " << tcpsock;
    fprintf(stderr, "ERR: Please implement _OnNewConnection(), now close socket %d.\n", tcpsock);
    return std::shared_ptr<StreamSocket>(nullptr);
}

void Server::NewConnection(int sock, int tag, const std::function<void ()>& cb)
{
    if (sock == INVALID_SOCKET)
        return;

    auto conn = _OnNewConnection(sock, tag);

    if (!conn)
    {
        Socket::CloseSocket(sock);
        return;
    }

    conn->SetOnDisconnect(cb);

    if (NetThreadPool::Instance().AddSocket(conn, EventTypeRead | EventTypeWrite))
        tasks_.AddTask(conn);
}

void Server::AtForkHandler()
{
    for (auto sock : slistenSocks_)
    {
        close(sock);
    }
}

void Server::DelListenSock(int sock)
{
    if (sock == INVALID_SOCKET)
        return;

    auto n = slistenSocks_.erase(sock);

    if (n != 1)
        ERR << "Failed DelListenSock " << sock;
    else
        INF << "Success DelListenSock " << sock;
}

