#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "MyLine.h"

using namespace std;
using Svec = vector<string>;
using Iset = set<int>;

class QueryResult
{
friend void print(ostream &output, const QueryResult &qr);

public:
    QueryResult() = default;
    QueryResult(const string &w, shared_ptr<Svec> f, const Line &l): sought(w), file(f), lines(l) {}
    //Iset::iterator begin() const { return lines.begin(); }
    //Iset::iterator end() const   { return lines.end(); }
    //shared_ptr<Svec> get_file() { return file; }
    
private:
    string sought;
    shared_ptr<Svec> file;
    Line lines;
};

#endif
