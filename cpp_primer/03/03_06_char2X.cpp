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

    return 0;
}
