#include <iostream>

using namespace std;

typedef unsigned long long ullong;

ullong fact(int num)
{
    ullong fact = 1;

    for (; num > 1; num--)
        fact *= num;

    return fact;
}

int main()
{
    int num;

    cout << "Enter numbers to calculate their factorils: " << endl;

    while (cin >> num)
        cout << "fact(" << num << ") = " << fact(num) << endl;

    return 0;
}
