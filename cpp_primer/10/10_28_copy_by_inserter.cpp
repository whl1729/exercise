#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

void print_list(list<int> &ilist)
{
    for (auto i: ilist)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    list<int> ilist, blist, flist;

    copy(vi.begin(), vi.end(), inserter(ilist, ilist.begin()));
    copy(vi.begin(), vi.end(), front_inserter(flist));
    copy(vi.begin(), vi.end(), back_inserter(blist));

    print_list(ilist);
    print_list(blist);
    print_list(flist);

    return 0;
}
