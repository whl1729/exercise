#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int len = 100;
    char arr[] = "never ";
    char brr[] = "give up";
    char crr[len] = {0};

    strcpy(crr, arr);

    for (int pos = 0; pos < len && crr[pos]; pos++)
        cout << crr[pos];
    cout << endl;

    strcat(crr, brr);

    for (int pos = 0; pos < len && crr[pos]; pos++)
        cout << crr[pos];
    cout << endl;

    return 0;
}
