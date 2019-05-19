#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    list<int> ilist;
    int num;

    cout << "Enter list's number: " << endl;
    while (cin >> num)
        ilist.push_back(num);

    auto last_zero = find(ilist.crbegin(), ilist.crend(), 0);

    cout << ((last_zero == ilist.crend()) ? "Not Found" : to_string(distance(last_zero, ilist.crend()))) << endl;
    //cout << ((last_zero == ilist.crend()) ? "Not Found" : to_string(last_zero.base() - ilist.begin() - 1)) << endl;

    return 0;
}
