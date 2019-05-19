#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[10];
    int brr[10];

    for (int pos = 0; pos < 10; pos++)
    {
        arr[pos] = pos;
        brr[pos] = arr[pos];
        
        cout << arr[pos] << ' ';
    }

    cout << endl;

    vector<int> vi;

    for (int pos = 0; pos < 10; pos++)
    {
        vi.push_back(pos);
    }

    for (auto it = vi.begin(); it != vi.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}
