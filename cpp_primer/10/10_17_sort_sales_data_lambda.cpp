#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data item;
    vector<Sales_data> svec;
    
    while (read(cin, item))
    {
        svec.push_back(item);
    }

    sort(svec.begin(), svec.end(), 
         [] (Sales_data &a, Sales_data &b) { return a.isbn() < b.isbn(); });

    cout << endl;
    
    for (auto &item: svec)
        print(cout, item);

    return 0;
}
