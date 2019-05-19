#ifndef __NOTQUERY_H__
#define __NOTQUERY_H__

#include "Query.h"

class NotQuery: public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) { 
        cout << "NotQuery(const Query&)" << endl;
    }
    string rep() const { 
        cout << "NotQuery::rep" << endl;
        return "~(" + query.rep() + ")"; 
    }
    QueryResult eval(const TextQuery&) const;
    Query query;
public:
    NotQuery() {}
    ~NotQuery() { }
};

inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

#endif
