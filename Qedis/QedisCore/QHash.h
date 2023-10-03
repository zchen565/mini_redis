#ifndef BERT_QHASH_H
#define BERT_QHASH_H

#include "QString.h"
#include "QHelper.h"

#include <unordered_map>

namespace qedis
{

using QHash = std::unordered_map<QString, QString, Hash>;


size_t HScanKey(const QHash& hash, size_t cursor, size_t count, std::vector<QString>& res);

}

#endif

