#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Sales_data.h"

using namespace std;
using std::placeholders::_1;

int main()
{
    vector<Sales_data> vs;
    Sales_data book("", 1, 50.0);
    Sales_data item;

    cout << "Enter some book transactions: " << endl;
    while (cin >> item)
        vs.push_back(item);

    auto iter = upper_bound(vs.begin(), vs.end(), book, 
                            cmpAvgPrice);

    if (iter == vs.end())
        cout << "not found" << endl;
    else
        cout << *iter << endl;

    return 0;
}
