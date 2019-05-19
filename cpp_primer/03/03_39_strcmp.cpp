#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s1, s2;
    char cmp;
    const int len = 100;
    char arr[len] = {0};
    char brr[len] = {};

    cout << "Enter two strings: " << endl;
    cin >> s1 >> s2;

    cmp = (s1 < s2) ? '<' : ((s1 > s2) ? '>' : '=');
    cout << "s1 " << cmp << " s2" << endl;

    for (int pos = 0; pos < s1.size() && pos < len - 1; pos++)
        arr[pos] = s1[pos];

    for (int pos = 0; pos < s2.size() && pos < len - 1; pos++)
        brr[pos] = s2[pos];

    int result = strcmp(arr, brr);
    cmp = (result < 0) ? '<' : ((result > 0) ? '>' : '=');
    cout << "s1 " << cmp << " s2" << endl;

    return 0;
}
