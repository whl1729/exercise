#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main()
{
    list<int> ilist;
    deque<int> odds;
    deque<int> evens;
    int num;

    cout << "Enter some numbers: " << endl;
    
    while (cin >> num)
        ilist.push_back(num);

    for (auto i : ilist)
    {
        if (i % 2)
            odds.push_back(i);
        else
            evens.push_back(i);
    }

    for (auto i : odds)
        cout << i << ' ';
    cout << endl;

    for (auto i : evens)
        cout << i << ' ';
    cout << endl;

    return 0;
}
