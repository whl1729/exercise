#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_map<string, size_t> word_count;
    unordered_set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    string word;

    while (cin >> word)
        if (exclude.find(word) == exclude.end())
            ++word_count[word];

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
