#include <forward_list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i;
    forward_list<int> ilist;
//    cout << "size=" << ilist.size() << endl;

    ilist.push_front(9);
    for (int i = 1; i < 5; ++i)
        ilist.push_front(i);

    forward_list<int>::iterator ite = ilist.begin();
    forward_list<int>::iterator ite2 = ilist.end();
    for (; ite != ite2; ++ite)
        cout << *ite << ' ';
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 1);
    if (ite != ilist.end())
        ilist.insert_after(ite, 99);

//    cout << "size=" << ilist.size() << endl;
    cout << *ite << endl;

    ite = ilist.begin();
    ite2 = ilist.end();
    for (; ite != ite2; ++ite)
        cout << *ite << ' ';
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 3);
    if (ite != ilist.end())
        cout << *(ilist.erase_after(ite)) << endl;

    ite = ilist.begin();
    ite2 = ilist.end();
    for (; ite != ite2; ++ite)
        cout << *ite << ' ';
    cout << endl;

    return 0;
}
