#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline string make_plural(int cnt, const string &word, const string &ending)
{
    return ((cnt > 1) ? word + ending : word);
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
                        [] (const string &s){ return s.size() > 6; });

    cout << cnt << make_plural(cnt, " word", "s") << " is longer than 6" << endl;

    return 0;
}
