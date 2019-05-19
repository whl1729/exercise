#include <bits/stl_tree.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    _Rb_tree<int, int, _Identity<int>, less<int>> itree;
    cout << itree.size() << endl;

    int arr[] = {10,7,8,15,5,6,11,13,12};

    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
        itree._M_insert_unique(arr[i]);

    _Rb_tree<int, int, _Identity<int>, less<int>>::iterator ite1 = itree.begin();
    auto ite2 = itree.end();

    cout << itree.size() << endl;
    for (; ite1 != ite2; ++ite1)
    {
        cout << *ite1 << "(" << ite1._M_node->_M_color << ") ";
    }
    cout << endl;

    return 0;
}
