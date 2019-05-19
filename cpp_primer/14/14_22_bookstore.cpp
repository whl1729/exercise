#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data item = string("Old Man and Sea");
    cout << item << endl;

    Sales_data total;
    cin >> total;
    
    if (!total.isbn().empty())
    {
        Sales_data trans;
        while (cin >> trans)
        {
            if (trans.isbn() == total.isbn())
                total += trans;
            else
            {
                cout << total << endl;
                total = trans;
            }
        }

        cout << total << endl;
    }
    else
    {
        cout << "No data?!" << endl;
    }

    return 0;
}
