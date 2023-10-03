#pragma once


#include "Server.h"

class Server1: public Server
{
public:
    bool    _Init() override;
    bool    _RunLogic() override;
    void    _Recycle() override;

    // Modifed in server2
    //std::shared_ptr<StreamSocket> _OnNewConnection(int fd, int tag) override;
};
