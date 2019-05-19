#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

bool compare_isbn(const Sales_data &item1, const Sales_data &item2)
{
    return item1.isbn() < item2.isbn();
}

int main()
{
    Sales_data item;
    vector<Sales_data> svec;
    
    while (read(cin, item))
    {
        svec.push_back(item);
    }

    sort(svec.begin(), svec.end(), compare_isbn);

    cout << endl;
    
    for (auto &item: svec)
        print(cout, item);

    return 0;
}
