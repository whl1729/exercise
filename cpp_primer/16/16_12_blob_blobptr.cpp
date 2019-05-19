#include <iostream>
#include "Blob.h"

using namespace std;

int main()
{
    Blob<int> ibb;

    for (int pos = 1; pos < 10; ++pos)
        ibb.push_back(pos);
    cout << ibb << endl;

    Blob<string> sbb{"ocean's", "apart", "day", "after", "day"};
    cout << sbb << endl;

    return 0;
}
