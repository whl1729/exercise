#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

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

class QueryResult;
struct Line;

class TextQuery
{
public:
    TextQuery(): file(new Svec) { }
    TextQuery(const string &name);
    QueryResult query(const string &target);

private:
    shared_ptr<Svec> file;
    map<string, Line> word_line;
    void read(ifstream &input);
    Line do_query(const string &sought);
    Line get_line(const string &word);
};

#endif
