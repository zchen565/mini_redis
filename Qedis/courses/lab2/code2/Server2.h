#pragma once

#include "Server.h"

class Server2: public Server
{
public:
    bool    _Init() override;
    bool    _RunLogic() override;
    void    _Recycle() override;

    // Different from server1
    std::shared_ptr<StreamSocket> _OnNewConnection(int fd, int tag) override;
};
