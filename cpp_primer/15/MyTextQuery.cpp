#include <sstream>
#include <cctype>
#include "MyTextQuery.h"
#include "MyQueryResult.h"
#include "MyQueryCommand.h"

using namespace std;
using Svec = vector<string>;
using Iset = set<int>;

TextQuery::TextQuery(const string &name): file(new Svec)
{
    ifstream input(name);
    read(input);
    input.close();
}

QueryResult TextQuery::query(const string &sought)
{
    return QueryResult(sought, file, do_query(sought));
}

Line TextQuery::do_query(const string &sought)
{
    QueryCommand qc(sought);
    char op;
    string word;
    Line lines(file->size());
    istringstream iss((sought[0] == '~' ? "" : "| ") + sought);

    while (qc.get_cmd(iss, op, word))
    {
        Line rhs = get_line(word);
        switch(op)
        {
            case ' ':
                break;
            case '~':
                lines = ~rhs;
                break;
            case '|':
                lines |= rhs;
                break;
            case '&':
                lines &= rhs;
                break;
            default:
                break;
        }
    }

    return lines;
}

Line TextQuery::get_line(const string &word)
{
    static Line empty_line(file->size());
    if (word_line.find(word) == word_line.end())
        return empty_line;
    else
        return Line(word_line[word]);
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
            if (ispunct(word[0])) word.erase(word.begin());
            if (ispunct(word[word.size()-1])) word.pop_back();

            word_line[word].insert(file->size() - 1);
        }
    }

    for (auto &wl : word_line)
        wl.second.num = file->size();
}
