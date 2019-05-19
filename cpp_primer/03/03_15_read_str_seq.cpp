#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> vs;
    string word;

    while (cin >> word)
        vs.push_back(word);

    for (auto v : vs)
        cout << v << ' ';

    cout << endl;

    return 0;
}
