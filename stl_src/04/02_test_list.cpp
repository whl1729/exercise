#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i;
    list<int> ilist;
    cout << "size=" << ilist.size() << endl;

    for (i = 0; i < 5; ++i)
        ilist.push_back(i);
    cout << "size=" << ilist.size() << endl;

    list<int>::iterator ite;
    for (ite = ilist.begin(); ite != ilist.end(); ++ite)
        cout << *ite << ' ';
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 3);
    if (ite != ilist.end())
        ilist.insert(ite, 99);

    cout << "size=" << ilist.size() << endl;
    cout << *ite << endl;

    for (ite = ilist.begin(); ite != ilist.end(); ++ite)
        cout << *ite << ' ';
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 1);
    if (ite != ilist.end())
        cout << *(ilist.erase(ite)) << endl;


    for (ite = ilist.begin(); ite != ilist.end(); ++ite)
        cout << *ite << ' ';
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 100);
    if (ite != ilist.end())
        ilist.insert(ite, 1000);


    for (ite = ilist.begin(); ite != ilist.end(); ++ite)
        cout << *ite << ' ';
    cout << endl;

    return 0;
}
