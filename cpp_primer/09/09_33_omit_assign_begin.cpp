#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10, 1);
    auto begin = v.begin();
    while (begin != v.end())
    {
        ++begin;
        begin = v.insert(begin, 42);
        ++begin;
    }

    for (auto i: v)
        cout << i << ' ';
    cout << endl;

    vector<int> w(10, 1);
    while (begin != w.end())
    {
        ++begin;
        w.insert(begin, 42);
        ++begin;
    }

    for (auto i: w)
        cout << i << ' ';
    cout << endl;

    return 0;
}
