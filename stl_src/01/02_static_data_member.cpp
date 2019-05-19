#include <iostream>
using namespace std;

template <typename T>
class testClass
{
public:
    static int _data;
};

template <> int testClass<int>::_data = 1;
template <> int testClass<char>::_data = 2;

int main()
{
    cout << testClass<int>::_data << " " << testClass<char>::_data << endl;

    testClass<int> obji1, obji2;
    testClass<char> objc1, objc2;

    cout << obji1._data << " " << obji2._data << endl;
    cout << objc1._data << " " << objc2._data << endl;

    return 0;
}
