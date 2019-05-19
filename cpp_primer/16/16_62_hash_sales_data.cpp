#include <iostream>
#include <unordered_set>
#include "Sales_data.h"

using namespace std;


int main()
{
    unordered_multiset<Sales_data> items;
    items.insert(Sales_data("C++ Primer", 5, 128.0));
    items.insert(Sales_data("The Old Man and The Sea", 3, 75.5));
    items.insert(Sales_data("Walden", 10, 36.2));

    for (auto &i : items)
        cout << i;

    return 0;
}
