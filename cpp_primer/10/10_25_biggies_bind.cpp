#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &str, string::size_type size)
{
    return str.size() >= size;
}

int main()
{
    string word;
    vector<string> vs;

    cout << "Enter some words: " << endl;
    while (cin >> word)
        vs.push_back(word);

    auto end_long = partition(vs.begin(), vs.end(), 
                              bind(check_size, _1, 5));

    for (auto vbeg = vs.begin(); vbeg != end_long; ++vbeg)
        cout << *vbeg << ' ';
    cout << endl;

    return 0;
}
