#include <iostream>

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main()
{
    int foo, bar;
    double app, pie;
    string cat, dog;

    cout << "Enter two integers:" << endl;
    cin >> foo >> bar;
    cout << compare(foo, bar) << endl;

    cout << "Enter two doubles:" << endl;
    cin >> app >> pie;
    cout << compare(app, pie) << endl;

    cout << "Enter two strings:" << endl;
    cin >> cat >> dog;
    cout << compare(cat, dog) << endl;

    return 0;
}
