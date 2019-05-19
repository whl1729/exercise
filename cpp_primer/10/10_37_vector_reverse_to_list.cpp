#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
    list<int> ilist;

    copy(ivec.crbegin() + 2, ivec.crbegin() + 6, back_inserter(ilist));

    for (auto i : ilist)
        cout << i << " ";
    cout << endl;

    return 0;
}
