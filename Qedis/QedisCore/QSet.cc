#include "QSet.h"
#include "QStore.h"
#include "QClient.h"
#include <cassert>

namespace qedis
{

QObject QObject::CreateSet()
{
    QObject set(QType_set);
    set.Reset(new QSet);

    return set;
}

#define GET_SET(setname)  \
    QObject* value;  \
    QError err = QSTORE.GetValueByType(setname, value, QType_set);  \
    if (err != QError_ok)  {  \
         if (err == QError_notExist)    \
             FormatNull(reply); \
         else   \
             ReplyError(err, reply);    \
        return err;  \
    }

#define GET_OR_SET_SET(setname)  \
    QObject* value;  \
    QError err = QSTORE.GetValueByType(setname, value, QType_set);  \
    if (err != QError_ok && err != QError_notExist)  {  \
        ReplyError(err, reply); \
        return err;  \
    }   \
    if (err == QError_notExist) { \
        value = QSTORE.SetValue(setname, QObject::CreateSet());  \
    }

static bool RandomMember(const QSet& set, QString& res)
{
    QSet::const_local_iterator it = RandomHashMember(set);

    if (it != QSet::const_local_iterator())
    {
        res = *it;
        return true;
    }

    return false;
}

QError spop(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    GET_SET(params[1]);

    auto set = value->CastSet();
    QString res;
    if (RandomMember(*set, res))
    {
        FormatBulk(res, reply);
        set->erase(res);
        if (set->empty())
            QSTORE.DeleteKey(params[1]);

        std::vector<QString> translated;
        translated.push_back("srem");
        translated.push_back(params[1]);
        translated.push_back(res);
        
        QClient::Current()->RewriteCmd(translated);
    }
    else
    {
        FormatNull(reply);
        return QError_notExist;
    }
    
    return QError_ok;
}


QError srandmember(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    GET_SET(params[1]);

    auto set = value->CastSet();
    QString res;
    if (RandomMember(*set, res))
    {
        FormatBulk(res, reply);
    }
    else
    {
        FormatNull(reply);
    }

    return QError_ok;
}

QError sadd(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    GET_OR_SET_SET(params[1]);
    
    int res = 0;
    auto set = value->CastSet();
    for (size_t i = 2; i < params.size(); ++ i)
    {
        if (set->insert(params[i]).second)
            ++ res;
    }
    
    FormatInt(res, reply);
    return QError_ok;
}

QError  scard(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    GET_SET(params[1]);

    auto set = value->CastSet();
    long size = static_cast<long>(set->size());
    
    FormatInt(size, reply);
    return QError_ok;
}

QError srem(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    GET_SET(params[1]);

    auto set = value->CastSet();
    int res = 0;
    for (size_t i = 2; i < params.size(); ++ i)
    {
        if (set->erase(params[i]) != 0)
            ++ res;
    }
    
    if (set->empty())
        QSTORE.DeleteKey(params[1]);
    
    FormatInt(res, reply);
    return QError_ok;
}

QError sismember(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    GET_SET(params[1]);
    
    auto set = value->CastSet();
    long res = static_cast<long>(set->count(params[2]));
    
    FormatInt(res, reply);
    return QError_ok;
}

QError smembers(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    GET_SET(params[1]);

    auto set = value->CastSet();
    PreFormatMultiBulk(set->size(), reply);
    for (const auto& member : *set)
        FormatBulk(member, reply);

    return QError_ok;
}

QError smove(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    GET_SET(params[1]);
    
    auto set = value->CastSet();
    int ret = static_cast<int>(set->erase(params[3]));
    if (ret != 0)
    {
        QObject* dst;
        err = QSTORE.GetValueByType(params[2], dst, QType_set);
        if (err == QError_notExist)
        {
            err = QError_ok;
            QObject val(QObject::CreateSet());
            dst = QSTORE.SetValue(params[2], std::move(val));
        }
        
        if (err == QError_ok)
        {
            auto dset = dst->CastSet();
            dset->insert(params[3]);
        }
    }
    
    FormatInt(ret, reply);
    return err;
}


QSet& QSet_diff(const QSet& l, const QSet& r, QSet& result)
{
    for (const auto& le : l)
    {
        if (r.count(le) == 0)
        {
            result.insert(le);
        }
    }

    return result;
}

QSet& QSet_inter(const QSet& l, const QSet& r, QSet& result)
{
    for (const auto& le : l)
    {
        if (r.count(le) != 0)
        {
            result.insert(le);
        }
    }

    return result;
}


QSet& QSet_union(const QSet& l, const QSet& r, QSet& result)
{
    for (const auto& re : r)
    {
        result.insert(re);
    }

    for (const auto& le : l)
    {
        result.insert(le);
    }
    
    return result;
}

enum SetOperation
{
    SetOperation_diff,
    SetOperation_inter,
    SetOperation_union,
};

static void  _set_operation(const std::vector<QString>& params,
                            size_t offset,
                            QSet& res,
                            SetOperation oper)
{
    QObject*  value;
    QError err = QSTORE.GetValueByType(params[offset], value, QType_set);
    if (err != QError_ok && oper != SetOperation_union)
        return;

    auto set = value->CastSet();
    if (set)
        res = *set;
    
    for (size_t i = offset + 1; i < params.size(); ++ i)
    {
        QObject*  val;
        QError err = QSTORE.GetValueByType(params[i], val, QType_set);
        if (err != QError_ok)
        {
            if (oper == SetOperation_inter)
            {
                res.clear();
                return;
            }
            continue;
        }
        
        QSet tmp;
        auto r = val->CastSet();
        if (oper == SetOperation_diff)
            QSet_diff(res, *r, tmp);
        else if (oper == SetOperation_inter)
            QSet_inter(res, *r, tmp);
        else if (oper == SetOperation_union)
            QSet_union(res, *r, tmp);
        
        res.swap(tmp);
        
        if (oper != SetOperation_union && res.empty())
            return;
    }
}

QError  sdiffstore(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    QObject obj(QObject::CreateSet());
    auto res = obj.CastSet();
    QSTORE.SetValue(params[1], std::move(obj));

    _set_operation(params, 2, *res, SetOperation_diff);

    FormatInt(static_cast<long>(res->size()), reply);
    return QError_ok;
}

QError sdiff(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    QSet res;
    _set_operation(params, 1, res, SetOperation_diff);
    
    PreFormatMultiBulk(res.size(), reply);
    for (const auto& elem : res)
        FormatBulk(elem, reply);
    
    return QError_ok;
}


QError sinter(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    QSet res;
    _set_operation(params, 1, res, SetOperation_inter);
    
    PreFormatMultiBulk(res.size(), reply);
    for (const auto& elem : res)
        FormatBulk(elem, reply);
    
    return QError_ok;
}

QError  sinterstore(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    QObject obj(QObject::CreateSet());
    auto res = obj.CastSet();
    QSTORE.SetValue(params[1], std::move(obj));

    _set_operation(params, 2, *res, SetOperation_inter);

    FormatInt(static_cast<long>(res->size()), reply);
    return QError_ok;
}


QError  sunion(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    QSet res;
    _set_operation(params, 1, res, SetOperation_union);
    
    PreFormatMultiBulk(res.size(), reply);
    for (const auto& elem : res)
        FormatBulk(elem, reply);
    
    return QError_ok;
}

QError  sunionstore(const std::vector<QString>& params, UnboundedBuffer* reply)
{
    QObject obj(QObject::CreateSet());
    auto res = obj.CastSet();
    QSTORE.SetValue(params[1], std::move(obj));

    _set_operation(params, 2, *res, SetOperation_union);

    FormatInt(static_cast<long>(res->size()), reply);
    return QError_ok;
}

size_t SScanKey(const QSet& qset, size_t cursor, size_t count, std::vector<QString>& res)
{
    if (qset.empty())
        return 0;
    
    std::vector<QSet::const_local_iterator>  iters;
    size_t newCursor = ScanHashMember(qset, cursor, count, iters);
    
    res.reserve(iters.size());
    for (auto it : iters)
        res.push_back(*it);
    
    return newCursor;
}

}
