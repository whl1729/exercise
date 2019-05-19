#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data total(cin);
    
    if (!total.isbn().empty())
    {
        while (cin)
        {
            Sales_data trans(cin);

            if (!cin)
                break;

            if (trans.isbn() == total.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }

        print(cout, total) << endl;
    }
    else
    {
        cout << "No data?!" << endl;
    }

    return 0;
}
