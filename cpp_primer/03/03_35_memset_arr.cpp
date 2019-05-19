#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};
    
    for (auto val : arr)
        cout << val << ' ';
    cout << endl;

    for (auto ptr = begin(arr); ptr < end(arr); ptr++)
        *ptr = 0;

    for (auto val : arr)
        cout << val << ' ';
    cout << endl;

    return 0;
}
