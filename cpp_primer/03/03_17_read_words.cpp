#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> vs;
    string word;
    int count = 0;

    while (cin >> word)
        vs.push_back(word);

    for (auto &s : vs)
    {
        for (auto &c : s)
            c= toupper(c);

        cout << s << ' ';

        if (++count % 8 == 0)
            cout << endl;
    }

    return 0;
}
