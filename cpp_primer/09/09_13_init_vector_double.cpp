#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> ivec{1, 4, 9, 16, 25};
    list<int> ilst(5, 100);

    vector<double> dvec1(ivec.begin(), ivec.end());
    vector<double> dvec2(ilst.begin(), ilst.end());

    for (auto v : dvec1)
        cout << v << ' ' << endl;
    cout << endl;

    for (auto v : dvec2)
        cout << v << ' ' << endl;
    cout << endl;

    return 0;
}
