#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int size = 100;
    int arr[size];

    for (int pos = 0; pos < 100; pos++)
        arr[pos] = (pos+1) * (pos+1);

    vector<int> ivec(begin(arr), end(arr));

    for (auto val : ivec)
    {
        cout << val << ' ';
        if (val % 10 == 0)
            cout << endl;
    }

    return 0;
}
