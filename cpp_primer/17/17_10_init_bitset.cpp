#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<22> foo("1000000010000100101110");
    bitset<22> bar;

    cout << "foo: " << foo << endl;

    int arr[] = {1,2,3,5,8,13,21};

    for (int pos = 0; pos < sizeof(arr) / sizeof(int); ++pos)
        bar.set(arr[pos]);
    cout << "bar: " << bar << endl;

    return 0;
}
