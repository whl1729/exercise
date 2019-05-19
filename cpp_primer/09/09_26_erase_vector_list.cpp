#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec;
    list<int> ilist;

    for (int pos = 0; pos < sizeof(ia) / sizeof(int); ++pos)
    {
        ivec.push_back(ia[pos]);
        ilist.push_back(ia[pos]);
    }

    auto vbeg = ivec.begin();
    auto lbeg = ilist.begin();

    while (vbeg != ivec.end())
    {
        if (*vbeg % 2 == 0)
            vbeg = ivec.erase(vbeg);
        else
            ++vbeg;
    }

    while (lbeg != ilist.end())
    {
        if (*lbeg % 2)
            lbeg = ilist.erase(lbeg);
        else
            ++lbeg;
    }

    for (auto i: ivec)
        cout << i << ' ';
    cout << endl;

    for (auto i: ilist)
        cout << i << ' ';
    cout << endl;

    return 0;
}
