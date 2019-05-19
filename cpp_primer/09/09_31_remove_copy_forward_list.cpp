#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> ilist = {0,1,2,3,4,5,6,7,8,9};
    auto iter = ilist.begin();
    auto prev = ilist.before_begin();
    while (iter != ilist.end())
    {
        if (*iter & 0x1)
        {
            iter = ilist.insert_after(iter, *iter);
            prev = iter++;
        }
        else
        {
            iter = ilist.erase_after(prev);
        }
    }

    for (auto i: ilist)
        cout << i << ' ';
    cout << endl;

    return 0;
}
