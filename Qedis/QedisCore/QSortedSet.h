#ifndef BERT_QSORTEDSET_H
#define BERT_QSORTEDSET_H

#include "QString.h"
#include "QHelper.h"
#include <map>
#include <set>
#include <vector>
#include <unordered_map>

namespace qedis
{

class QSortedSet
{
public:
    using Members = std::set<QString>;
    using Score2Members = std::map<double, Members>;

    using Member2Score = std::unordered_map<QString, double,
                                            Hash>;//,
                                            //std::equal_to<QString> >;

    Member2Score::iterator FindMember(const QString& member);
    Member2Score::const_iterator begin() const {  return members_.begin(); };
    Member2Score::iterator begin() {  return members_.begin(); };
    Member2Score::const_iterator end() const {  return members_.end(); };
    Member2Score::iterator end() {  return members_.end(); };
    void    AddMember   (const QString& member, double score);
    double  UpdateMember(const Member2Score::iterator& itMem, double delta);

    int     Rank        (const QString& member) const;// 0-based
    int     RevRank     (const QString& member) const;// 0-based
    bool    DelMember   (const QString& member);
    Member2Score::value_type
        GetMemberByRank(std::size_t rank) const;
    
    std::vector<Member2Score::value_type >
        RangeByRank(long start, long end) const;

    std::vector<Member2Score::value_type >
        RangeByScore(double minScore, double maxScore);

    std::size_t Size() const;

private:
    Score2Members   scores_;
    Member2Score    members_;
};

}

#endif

