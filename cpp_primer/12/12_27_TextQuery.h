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

using namespace std;
using Svec = vector<string>;
using Mssi = map<string, set<int>>;
using Msi  = map<string, int>;

class QueryResult;

class TextQuery
{
public:
    TextQuery(): text(make_shared<Svec>()), word_line(make_shared<Mssi>()),
                      word_count(make_shared<Msi>()) {}
    TextQuery(const string &file): text(make_shared<Svec>()), 
                                   word_line(make_shared<Mssi>()),
                                   word_count(make_shared<Msi>()) 
    {
        ifstream input(file);
        read(input);
        input.close();
        
    }

    QueryResult query(const string &target);

private:
    shared_ptr<Svec> text;
    shared_ptr<Mssi> word_line;
    shared_ptr<Msi> word_count;
    void read(ifstream &input);
};

class QueryResult
{
friend void print(ostream &output, const QueryResult &qr);

public:
    QueryResult() = default;
    QueryResult(const string &w, int c, shared_ptr<Svec> t, shared_ptr<Mssi> l): word(w), count(c), text(t), line(l) {}

private:
    string word;
    int count;
    shared_ptr<Svec> text;
    shared_ptr<Mssi> line;
};

QueryResult TextQuery::query(const string &target)
{
    return ((word_count->find(target) == word_count->end()) ?
             QueryResult{target, 0, nullptr, nullptr} :
             QueryResult{target, (*word_count)[target], text, word_line});
}

void TextQuery::read(ifstream &input)
{
    string line, word;

    while (getline(input, line))
    {
        text->push_back(line);

        istringstream iss(line);
        while (iss >> word)
        {
            (*word_line)[word].insert(text->size());
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
        cout << "    (line " << l << ") " << (*qr.text)[l-1] << endl;
}

#endif
