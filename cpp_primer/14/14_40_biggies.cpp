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

struct StrCmp
{
    bool operator()(const string &lhs, const string &rhs) const
        { lhs.size() < rhs.size(); }
};

class ShortStr
{
public:
    ShortStr(size_t len = 0): sz(len) { }
    bool operator()(const string &s) { return s.size() < sz; }
private:
    size_t sz;
};

class PrintStr
{
public:
    PrintStr(ostream &os = cout): output(os) { }
    ostream &operator()(const string &s) { output << s << " "; }
private:
    ostream &output;
};

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elim_dups(words);

    stable_sort(words.begin(), words.end(), StrCmp());

    auto wc = partition(words.begin(), words.end(), ShortStr(sz));

    auto count = words.end() - wc;
    
    cout << count << make_plural(count, " words", "s")
         << " of length " << sz << " or longer" << endl;

    for_each(wc, words.end(), PrintStr());

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
