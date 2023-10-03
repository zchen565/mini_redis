#ifndef BERT_QMULTI_H
#define BERT_QMULTI_H

#include <map>
#include <vector>
#include <memory>
#include "QString.h"

namespace qedis
{

class QClient;
class QMulti
{
public:
    static QMulti& Instance();

    QMulti(const QMulti& ) = delete;
    void operator= (const QMulti& ) = delete;

    void  Watch(QClient* client, int dbno, const QString& key);
    bool  Multi(QClient* client);
    bool  Exec(QClient* client);
    void  Discard(QClient* client);

    void  NotifyDirty(int dbno, const QString& key);
    void  NotifyDirtyAll(int dbno);
private:
    QMulti() {}

    using Clients = std::vector<std::weak_ptr<QClient> >;
    using WatchedClients = std::map<int, std::map<QString, Clients> >;
    
    WatchedClients  clients_;
};

}

#endif

