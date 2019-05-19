#include <iostream>
#include "Chapter6.h"

using namespace std;

int main()
{
    unsigned num;

    cout << "Enter numbers to calculate their factorils: " << endl;

    while (cin >> num)
        cout << "fact(" << num << ") = " << fact(num) << endl;

    return 0;
}
