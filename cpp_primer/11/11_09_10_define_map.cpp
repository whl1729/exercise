#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <utility>

using namespace std;

int main()
{
    map<string, list<string>> msl;
    vector<int> ivec;
    list<int> ilist;
    map<vector<int>::iterator, int> mvi;
    map<list<int>::iterator, int> mli;

    mvi.insert(pair<vector<int>::iterator, int>(ivec.begin(), 0));
    // mli.insert(pair<list<int>::iterator, int>(ilist.begin(), 0));

    return 0;
}
