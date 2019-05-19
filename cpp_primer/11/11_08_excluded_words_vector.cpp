#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> excluded;
    string word;

    cout << "Enter some words: " << endl;
    while (cin >> word)
    {
        auto vbeg = excluded.begin();
        for (; vbeg != excluded.end(); ++vbeg)
            if (*vbeg == word)
                break;
        if (vbeg == excluded.end())
            excluded.push_back(word);
    }

    for (auto &e : excluded)
        cout << e << ' ';
    cout << endl;

    return 0;
}
