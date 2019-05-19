#ifndef __ANDQUERY_H__
#define __ANDQUERY_H__

#include "BinaryQuery.h"

class AndQuery: public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "&") {
        cout << "AndQuery(const Query&, const Query&)" << endl;
    }
    QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif
