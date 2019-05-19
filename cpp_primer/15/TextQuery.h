#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

using namespace std;

class QueryResult;

class TextQuery
{
public:
    using Svec = vector<string>;
    using line_no = vector<string>::size_type;
    using Iset = set<line_no>;
    using Mspi = map<string, shared_ptr<Iset>>;

    TextQuery(): file(new Svec) { }
    TextQuery(const string &name);
    QueryResult query(const string &target) const;

private:
    shared_ptr<Svec> file;
    Mspi word_line;
    void read(ifstream &input);
};

#endif
