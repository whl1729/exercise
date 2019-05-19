#ifndef __ORQUERY_H__
#define __ORQUERY_H__

#include "BinaryQuery.h"

class OrQuery: public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|") {
            cout << "OrQuery(const Query&, const Query&)" << endl;
    }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif
