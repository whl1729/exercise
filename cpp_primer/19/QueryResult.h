#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "TextQuery.h"

using namespace std;

class QueryResult
{
friend void print(ostream &output, const QueryResult &qr);
friend ostream& operator<<(ostream &output, const QueryResult &qr);

public:
    using Iset = TextQuery::Iset;
    using Svec = TextQuery::Svec;
    QueryResult() = default;
    QueryResult(const string &w, shared_ptr<Iset> l, shared_ptr<Svec> f): 
        sought(w), lines(l), file(f) {}
    Iset::iterator begin() { return lines->begin(); }
    Iset::iterator end()   { return lines->end(); }
    shared_ptr<Svec> get_file() { return file; }
    
private:
    string sought;
    shared_ptr<Iset> lines;
    shared_ptr<Svec> file;
};

#endif
