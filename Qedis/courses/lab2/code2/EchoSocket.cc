#include "Log/Logger.h"

#include "EchoSocket.h"


PacketLength EchoSocket::_HandlePacket(const char* data, size_t bytes)
{
    // 判断是否踢掉连接
    if (bytes >= 3 && strncmp(data, "bye", 3) == 0) {
        this->OnError(); // 调用OnError就会踢掉连接!
        return 0;
    }

    // 将数据原封不动的echo回去
    SendPacket(data, bytes);

    // 告知网络库，我们消费了多少字节
    return bytes;
}

