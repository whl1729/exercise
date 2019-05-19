#ifndef __QUERY_H__
#define __QUERY_H__

#include <iostream>
#include <string>
#include <memory>
#include "Query_base.h"
#include "WordQuery.h"

using std::shared_ptr;
using std::ostream;
using std::cout;
using std::endl;

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
public:
    Query(const string &);
    QueryResult eval(const TextQuery &t) const {
        cout << "Query::eval" << endl;
        return q->eval(t); 
    }
    string rep() const { 
        cout << "Query::rep" << endl;
        return q->rep(); 
    }
private:
    Query(shared_ptr<Query_base> query): q(query) { 
        cout << "Query(shared_ptr<Query_base>)" << endl;
    }
    shared_ptr<Query_base> q;
};

ostream &operator<<(ostream &os, const Query &query);

inline Query::Query(const string &s): q(new WordQuery(s)) 
{
    cout << "Query(const string &s) where s=" << s << endl;
}

#endif
