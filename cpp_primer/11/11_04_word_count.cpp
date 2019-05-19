#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>

using namespace std;

string to_lower_and_del_punc(string &word)
{
    string str;
    for (auto c : word)
        if (isalpha(c))
            str.push_back(tolower(c));

    return str;
}

int main()
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    string word;

    while (cin >> word)
        if (exclude.find(word) == exclude.end())
            ++word_count[to_lower_and_del_punc(word)];

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
