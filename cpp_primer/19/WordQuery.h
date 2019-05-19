#ifndef __WORDQUERY_H__
#define __WORDQUERY_H__

#include "Query_base.h"
#include "TextQuery.h"

class WordQuery : public Query_base
{
    friend class Query;
    WordQuery(const string &s): query_word(s) 
    {
        cout << "WordQuery(const string &s) where s=" << s << endl;
    }
    QueryResult eval(const TextQuery &t) const { 
        cout << "WordQuery::eval" << endl;
        return t.query(query_word); 
    }
    string rep() const { 
        cout << "WordQuery::rep" << endl;
        return query_word; 
    }
    string query_word;
};

#endif
