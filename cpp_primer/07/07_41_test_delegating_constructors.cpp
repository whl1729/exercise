#include "07_41_Sales_data.h"

using namespace std;

int main()
{
    cout << "Sales_data a;" << endl;
    Sales_data a;
    print(cout, a) << endl;

    cout << "Sales_data b(\"Math\");" << endl;
    Sales_data b("Math");
    print(cout, b) << endl;

    cout << "Sales_data c(cin)" << endl;
    Sales_data c(cin);
    print(cout, c) << endl;

    cout << "Sales_data d(\"Warden Lake\", 5, 100);" << endl;
    Sales_data d("Warden Lake", 5, 100);
    print(cout, d) << endl;

    return 0;
}
