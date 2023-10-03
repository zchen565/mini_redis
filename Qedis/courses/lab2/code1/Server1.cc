
#include <iostream>

#include "Log/Logger.h"
#include "Socket.h"

#include "Server1.h"

bool Server1::_Init()
{
    // 初始化log相关
    g_log = LogManager::Instance().CreateLog(logALL, logConsole, "");

    // 监听端口9800
    SocketAddr addr("127.0.0.1", 9800);
    if (!Server::TCPBind(addr, 0))
    {
        ERR << "can not bind socket on port " << addr.GetPort();
        return false;
    }

    // 不要忘记return true, 否则程序起不来
    return true;
}

bool Server1::_RunLogic()
{
    static int c = 0;
    if (++c % 20000 == 0)
        DBG << "Server1::_RunLogic";

    return Server::_RunLogic();
}

void Server1::_Recycle()
{
    std::cout << "Server1::_Recycle: server is exiting.. BYE BYE\n";
}


int main(int ac, char* av[])
{
    Server1 svr;

    // 进入主循环，会自动先调用_Init函数，再循环调用 _RunLogic
    svr.MainLoop(false);

    return 0;
}

