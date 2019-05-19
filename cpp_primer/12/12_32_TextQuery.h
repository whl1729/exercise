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
#include "StrBlob.h"

using namespace std;
using Svec = vector<string>;
using Mssi = map<string, set<int>>;
using Msi  = map<string, int>;

class QueryResult;

class TextQuery
{
public:
    TextQuery(): word_line(make_shared<Mssi>()),
                 word_count(make_shared<Msi>()) {}
    TextQuery(const string &file): word_line(make_shared<Mssi>()),
                                   word_count(make_shared<Msi>()) 
    {
        ifstream input(file);
        read(input);
        input.close();
        
    }

    QueryResult query(const string &target);

private:
    StrBlob text;
    shared_ptr<Mssi> word_line;
    shared_ptr<Msi> word_count;
    void read(ifstream &input);
};

class QueryResult
{
friend void print(ostream &output, const QueryResult &qr);

public:
    QueryResult() = default;
    QueryResult(const string &w, int c, const StrBlob &t, shared_ptr<Mssi> l): word(w), count(c), text(t), line(l) {}

private:
    string word;
    int count;
    StrBlob text;
    shared_ptr<Mssi> line;
};

QueryResult TextQuery::query(const string &target)
{
    return ((word_count->find(target) == word_count->end()) ?
             QueryResult{target, 0, text, nullptr} :
             QueryResult{target, (*word_count)[target], text, word_line});
}

void TextQuery::read(ifstream &input)
{
    string line, word;

    while (getline(input, line))
    {
        text.push_back(line);

        istringstream iss(line);
        while (iss >> word)
        {
            (*word_line)[word].insert(text.size());
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

    for (auto &l: (*qr.line)[qr.word])
    {
        StrBlobPtr blob(qr.text, l-1);
        cout << "    (line " << l << ") " << blob.deref() << endl;
    }
}

#endif
