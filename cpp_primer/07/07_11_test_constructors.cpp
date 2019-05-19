#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data item1;
    Sales_data item2("Surely you're joking, Feynman");
    Sales_data item3("Gone", 3, 58.20);
    Sales_data item4(cin);

    print(cout, item1);
    print(cout, item2);
    print(cout, item3);
    print(cout, item4);

    return 0;
}
