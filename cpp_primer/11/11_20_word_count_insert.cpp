#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> word_count;
    string word;

    cout << "Enter some words:" << endl;

    while (cin >> word)
    {
        auto result = word_count.insert({word, 1});
        if (!result.second)
            ++result.first->second;
    }

    for (auto &w : word_count)
        cout << w.first << " occurs " << w.second 
             << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
