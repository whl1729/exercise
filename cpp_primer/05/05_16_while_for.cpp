#include <iostream>

using namespace std;

int main()
{
    int num;

    while ((cin >> num) && (num != 0))
        cout << num << endl;

    cout << "End while 1." << endl;

    for (; (cin >> num) && (num != 0); )
        cout << num * num << endl;

    cout << "End for 1." << endl;

    for (int pos = 1; pos <= 100; pos++)
    {
        cout << pos * pos * pos << ' ';
        if (pos % 10 == 0)
            cout << endl;
    }

    cout << "End for 2." << endl;

    int pos = 0;
    while (++pos <= 100)
    {
        cout << pos * pos * pos * pos << ' ';
        if (pos % 10 == 0)
            cout << endl;
    }

    cout << "End while 2." << endl;

    return 0;
}
