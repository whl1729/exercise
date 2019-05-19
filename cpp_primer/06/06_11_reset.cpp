#include <iostream>

using namespace std;

void reset(int &num)
{
    num = 0;
}

int main()
{
    int num;

    cout << "Enter a number: " << endl;
    cin >> num;

    reset(num);

    cout << "after reset, num=" << num << endl;

    return 0;
}
