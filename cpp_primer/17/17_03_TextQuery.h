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
using Mspi = map<string, shared_ptr<set<int>>>;
using Msi  = map<string, int>;
using Iset = set<int>;

typedef tuple<string, int, shared_ptr<Svec>, shared_ptr<Iset>> QueryResult;

class TextQuery
{
public:
    TextQuery(): file(new Svec), word_count(make_shared<Msi>()) {}
    TextQuery(const string &name): file(new Svec), word_count(new Msi) 
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
    if (get<1>(qr) <= 0)
    {
        cout << get<0>(qr) << " occurs 0 time." << endl;
        return;
    }

    cout << get<0>(qr) << " occurs " << get<1>(qr)
         << (get<1>(qr) > 1 ? " times" : " time") << endl;

    for (auto &l: *get<3>(qr))
        cout << "    (line " << l << ") " << (*get<2>(qr))[l-1] << endl;
}

#endif
