#include <sstream>
#include <cctype>
#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery(const string &name): file(new Svec)
{
    ifstream input(name);
    read(input);
    input.close();
}

QueryResult TextQuery::query(const string &target) const
{
    static shared_ptr<Iset> nodata(new Iset);
    auto loc = word_line.find(target);

    return ((loc == word_line.end()) ?
             QueryResult{target, nodata, file} :
             QueryResult{target, loc->second, file});
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

            if (!word_line[word])
                word_line[word].reset(new Iset);
            
            word_line[word]->insert(file->size() - 1);
        }
    }
}
