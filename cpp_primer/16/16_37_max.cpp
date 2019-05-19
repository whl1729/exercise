#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int insect = 10;
    double pi = 3.14;
    cout << max<double>(insect, pi) << endl;
    cout << max<int>(insect, pi) << endl;

    return 0;
}
