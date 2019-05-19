#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "DebugDelete.h"

using namespace std;
using Svec = vector<string>;
using Mspi = map<string, shared_ptr<set<int>>>;
using Msi  = map<string, int>;
using Iset = set<int>;

class QueryResult;

class TextQuery
{
public:
    TextQuery(): file(new Svec(), DebugDelete()), 
                 word_count(new Msi(), DebugDelete()) {}
    TextQuery(const string &name): file(new Svec, DebugDelete()), 
                                    word_count(new Msi, DebugDelete()) 
    {
        ifstream input(name);
        read(input);
        input.close();
    }

    QueryResult query(const string &target);

private:
    shared_ptr<Svec> file;
    Mspi word_line;
    shared_ptr<Msi> word_count;
    void read(ifstream &input);
};

class QueryResult
{
friend void print(ostream &output, const QueryResult &qr);

public:
    QueryResult() = default;
    QueryResult(const string &w, int c, shared_ptr<Svec> t, shared_ptr<Iset> l): word(w), count(c), file(t), line(l) {}
    Iset::iterator begin() { return line->begin(); }
    Iset::iterator end()   { return line->end(); }
    shared_ptr<Svec> get_file() { return file; }
    
private:
    string word;
    int count;
    shared_ptr<Svec> file;
    shared_ptr<Iset> line;
};

QueryResult TextQuery::query(const string &target)
{
    return ((word_count->find(target) == word_count->end()) ?
             QueryResult{target, 0, nullptr, nullptr} :
             QueryResult{target, (*word_count)[target], file, word_line[target]});
}

void TextQuery::read(ifstream &input)
{
    string line, word;

    while (getline(input, line))
    {
        file->push_back(line);

        istringstream iss(line);
        while (iss >> word)
        {
            if (!word_line[word])
                word_line[word].reset(new Iset);
            
            word_line[word]->insert(file->size());
            ++(*word_count)[word];
        }
    }
}

void print(ostream &output, const QueryResult &qr)
{
    if (qr.count <= 0)
    {
        cout << qr.word << " occurs 0 time." << endl;
        return;
    }

    cout << qr.word << " occurs " << qr.count
         << (qr.count > 1 ? " times" : " time") << endl;

    for (auto &l: *qr.line)
        cout << "    (line " << l << ") " << (*qr.file)[l-1] << endl;
}

#endif
