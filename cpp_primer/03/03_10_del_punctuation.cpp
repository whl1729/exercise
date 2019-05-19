#include <iostream>

using namespace std;

int main()
{
    string str;

    cout << "Enter a string: " << endl;
    cin >> str;

    for (auto c : str)
        if (!ispunct(c))
            cout << c;

    cout << endl;

    return 0;
}
