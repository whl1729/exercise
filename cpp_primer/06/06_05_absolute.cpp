#include <iostream>

using namespace std;

int absolute(long num)
{
    return (num > 0 ? num : (-num));
}

int main()
{
    long num;

    cout << "Enter numbers to calculate their absolute value: " << endl;

    while (cin >> num)
        cout << "abs(" << num << ") = " << absolute(num) << endl;

    return 0;
}
