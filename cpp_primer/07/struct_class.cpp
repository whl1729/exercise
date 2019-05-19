#include <iostream>

using namespace std;

//template <struct T>
template <class T>
int compare(T a, T b)
{
    return (a < b) ? 1 : 0;
}

int main()
{
    cout << compare(1, 2) << endl;
    return 0;
}
