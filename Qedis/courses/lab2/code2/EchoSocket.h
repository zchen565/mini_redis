#pragma once

#include "StreamSocket.h"


class EchoSocket : public StreamSocket
{
private:
    // 必须实现这个函数，对消息做处理，并回包
    PacketLength _HandlePacket(const char* msg, std::size_t len) override;
};

