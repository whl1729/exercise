#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool equal(const vector<int> &foo, const list<int> &bar)
{
    if (foo.size() != bar.size())
        return false;

    auto f = foo.begin();
    auto b = bar.begin();
    for (; f != foo.end() && b != bar.end(); ++f, ++b)
        if (*f != *b)
            return false;

    return true;
}

int main()
{
    vector<int> ivec;
    list<int> jlist;
    int num;

    cout << "Enter vector: " << endl;

    while (cin >> num)
        ivec.push_back(num);

    cin.clear();

    cout << "Enter list: " << endl;

    while (cin >> num)
        jlist.push_back(num);

    cout << (equal(ivec, jlist) ? "equal" : "not equal") << endl;

    return 0;
}
