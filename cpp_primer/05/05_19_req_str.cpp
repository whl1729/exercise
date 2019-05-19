#include <iostream>

using namespace std;

int main()
{
    string str1, str2;

    do {
        cin >> str1 >> str2;
        cout << str1 << " is " << ((str1 < str2) ? "less than " : (str1 == str2) ? "equal to " : "larger than ") << str2 << endl;
    } while (cin);

    return 0;
}
