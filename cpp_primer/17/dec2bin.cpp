#include <iostream>

using namespace std;

int main()
{
    unsigned num;

    cout << "Enter numbers: " << endl;
    while (cin >> num)
    {
        for (int i = 31; i >= 0; --i)
            cout << ((num & (1 << i)) ? '1' : '0');
        cout << endl;
    }
    
    return 0;
}
