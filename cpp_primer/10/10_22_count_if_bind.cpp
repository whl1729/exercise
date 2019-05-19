#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

inline string make_plural(int cnt, const string &word, const string &ending)
{
    return ((cnt > 1) ? word + ending : word);
}

bool is_shorter(const string &str, string::size_type size)
{
    return str.size() <= size;
}

int main()
{
    string word;
    vector<string> vs;
    decltype(vs.size()) size;

    cout << "Enter some words: " << endl;
    while (cin >> word)
        vs.push_back(word);

    cin.clear();
    cout << "Enter size: " << endl;
    cin >> size;

    auto cnt = count_if(vs.begin(), vs.end(), 
                        bind(is_shorter, _1, size));

    cout << cnt << make_plural(cnt, " word", "s") << " is no longer than 6" << endl;

    return 0;
}
