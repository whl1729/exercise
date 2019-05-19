#include <iostream>

using namespace std;

int main()
{
    string str;

    cout << "Enter a string: " << endl;
    cin >> str;

    for (auto &c : str)
        c = 'X';

    cout << str << endl;

    for (int pos = 0; pos < str.size(); pos++)
        str[pos] = 'Y';

    cout << str << endl;

    int pos = -1;
    while (++pos < str.size())
        str[pos] = 'Z';

    cout << str << endl;

    return 0;
}
