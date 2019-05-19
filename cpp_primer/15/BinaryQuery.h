#ifndef __BINARYQUERY_H__
#define __BINARYQUERY_H__

#include "Query.h"

class BinaryQuery: public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, string s):
        lhs(l), rhs(r), opSym(s) 
    {
        cout << "BinaryQuery(const Query&, const Query&, string)" << endl;
    }
    string rep() const { 
        cout << "BinaryQuery::rep" << endl;
        return "(" + lhs.rep() + " "
                    + opSym +  " "
                    + rhs.rep() + ")"; 
    }
    Query lhs, rhs;
    string opSym;
};

#endif
