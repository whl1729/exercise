#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data total;
    cout << "Enter some transactions: " << endl;
    cin >> total;
    cout << string(" I like it.") + total << endl;
    double pi = total;
    string name = total;
    cout << pi << " " << name << endl;
    
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
