#include <iostream>
#include <functional>

using namespace std;

int main()
{
    logical_and<int> and_obj;
    logical_or<int> or_obj;
    logical_not<int> not_obj;

    cout << boolalpha;
    cout << and_obj(true, true) << endl;
    cout << or_obj(true, false) << endl;
    cout << not_obj(true) << endl;

    cout << logical_and<int>()(true, true) << endl;
    cout << logical_or<int>()(true, false) << endl;
    cout << logical_not<int>()(true) << endl;

    cout << noboolalpha;

    return 0;
}
