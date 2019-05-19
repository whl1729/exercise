#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void elim_dups(vector<string> &vs)
{
    sort(vs.begin(), vs.end());

    auto end_uniq = unique(vs.begin(), vs.end());

    vs.erase(end_uniq, vs.end());
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elim_dups(words);

    stable_sort(words.begin(), words.end(), 
                [] (const string &a, const string &b)
                { return a.size() < b.size(); });

    auto wc = stable_partition(words.begin(), words.end(),
              [sz](const string &a) { return a.size() < sz; });

    auto count = words.end() - wc;
    
    cout << count << make_plural(count, " words", "s")
         << " of length " << sz << " or longer" << endl;

    for_each(wc, words.end(),
             [] (const string &s) { cout << s << " "; } );
    cout << endl;
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

    biggies(vs, size);

    return 0;
}
