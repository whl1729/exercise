#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data item1, item2, sum;

    cout << "Enter two transactions to count their sum:" << endl;
    while (cin >> item1 >> item2)
    {
        try
        {
            sum = item1 + item2;
            cout << "sum: " << sum << endl;
        }
        catch (const isbn_mismatch &e)
        {
            cout << e.what() << ": left isbn(" << e.left
                 << ") right isbn(" << e.right << ")" << endl;
        }
    }

    return 0;
}
