#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data item1, item2, sum;

    cout << "Enter two transactions to count their sum:" << endl;
    while (cin >> item1 >> item2)
    {
        sum = item1 + item2;
        cout << "sum: " << sum << endl;
    }

    return 0;
}
