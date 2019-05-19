#include <iostream>
#include "Chapter6.h"

using namespace std;

int main()
{
    for (int i = 0; i < 100; i++)
    {
        cout << count() << ' ';

        if (i % 10 == 9)
            cout << endl;
    }

    return 0;
}

int count()
{
    static int num = 0;
    return num++;
}

