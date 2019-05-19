#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    string bstr;
    cout << "Enter a binary string:" << endl;
    while (cin >> bstr)
    {
        bitset<8> bv(bstr);
        cout << bv << endl;
    }

    return 0;
}
