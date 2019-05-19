#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void print_vector(const vector<string> &vs)
{
    for (auto &s: vs)
        cout << s << ' ';
    cout << endl;
}

void elim_dups(vector<string> &vs)
{
    sort(vs.begin(), vs.end());

    print_vector(vs);

    auto end_uniq = unique(vs.begin(), vs.end());

    print_vector(vs);

    vs.erase(end_uniq, vs.end());

    print_vector(vs);
}

bool is_shorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string word;
    vector<string> vs;

    cout << "Enter some words: " << endl;
    while (cin >> word)
        vs.push_back(word);

    elim_dups(vs);

    stable_sort(vs.begin(), vs.end(), is_shorter);

    print_vector(vs);

    return 0;
}
