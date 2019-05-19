#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s1, s2;
    int len1, len2;

    cout << "\nEnter two strings: " << endl;
    cin >> s1 >> s2;

    if (s1 == s2)
        cout << s1 << " is equal to " << s2 << endl;
    else if (s1 < s2)
        cout << s1 << " is smaller than " << s2 << endl;
    else
        cout << s1 << " is larger than " << s2 << endl;

    cout << "\nEnter two strings: " << endl;
    cin >> s1 >> s2;

    len1 = s1.size();
    len2 = s2.size();

    if (len1 == len2)
        cout << s1 << " is as long as " << s2 << endl;
    else if (len1 < len2)
        cout << s1 << " is shorter than " << s2 << endl;
    else
        cout << s1 << " is longer than " << s2 << endl;

    return 0;
}
