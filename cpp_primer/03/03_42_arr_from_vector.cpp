#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    const int size = 100;
    int arr[size];
    int pos = 0;

    for (int num = 1; num <= size; num++)
        vi.push_back(num * num * num);

    for (auto val : vi)
        arr[pos++] = val;

    for (auto val : arr)
    {
        cout << val << ' ';

        if (val % 10 == 0)
            cout << endl;
    }

    return 0;
}
