#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class TextQuery
{
public:
    TextQuery() = default;
    TextQuery(ifstream &input) { read(input); }
    TextQuery(const string &file);
    void text_query(const string &target);
private:
    vector<string> text;
    map<string, set<int>> word_line;
    map<string, int> word_count;
    void read(ifstream &input);
};

TextQuery::TextQuery(const string &file)
{
    ifstream input(file);
    read(input);
    input.close();
}

void TextQuery::text_query(const string &target)
{
    if (word_count.find(target) == word_count.end())
    {
        cout << target << " occurs 0 time." << endl;
        return;
    }

    cout << target << " occurs " << word_count[target]
         << (word_count[target] > 1 ? " times" : " time") << endl;

    for (auto &l: word_line[target])
        cout << "    (line " << l << ") " << text[l-1] << endl;
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
            word_line[word].insert(text.size());
            ++word_count[word];
        }
    }
}

#endif
