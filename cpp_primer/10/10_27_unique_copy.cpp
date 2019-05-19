#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int num;
    vector<int> vi;
    list<int> ilist;

    cout << "Enter numbers:" << endl;
    while (cin >> num)
        vi.push_back(num);
    
    unique_copy(vi.cbegin(), vi.cend(), back_inserter(ilist));

    for (auto i: ilist)
        cout << i << ' ';
    cout << endl;

    return 0;
}
