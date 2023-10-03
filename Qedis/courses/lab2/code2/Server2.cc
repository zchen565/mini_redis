
#include <iostream>

#include "Log/Logger.h"
#include "EchoSocket.h"

#include "Server2.h"

const int kEchoTag = 1;

bool Server2::_Init()
{
    // 初始化log相关
    g_log = LogManager::Instance().CreateLog(logALL, logConsole, "");

    // 监听端口9800
    SocketAddr addr("127.0.0.1", 9800);
    if (!Server::TCPBind(addr, kEchoTag))
    {
        ERR << "can not bind socket on port " << addr.GetPort();
        return false;
    }

    // 不要忘记return true, 否则程序起不来
    return true;
}

bool Server2::_RunLogic()
{
    static int c = 0;
    if (c++ % 50000 == 0)
        DBG << "Server2::_RunLogic";

    return Server::_RunLogic();
}

void Server2::_Recycle()
{
    std::cout << "Server2::_Recycle: server is exiting.. BYE BYE\n";
}

std::shared_ptr<StreamSocket> Server2::_OnNewConnection(int fd, int tag) {
    assert (tag == kEchoTag);

    // 调用::getsockname获取对方的地址
    SocketAddr peer;
    Socket::GetPeerAddr(fd, peer);

    // 初始化EchoSocket对象并返回
    auto socket = std::make_shared<EchoSocket>();
    socket->Init(fd, peer);
    return socket;
}

int main(int ac, char* av[])
{
    Server2 svr;

    // 进入主循环，会自动先调用_Init函数，再循环调用 _RunLogic
    svr.MainLoop(false);

    return 0;
}

