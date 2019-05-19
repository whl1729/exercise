#include <iostream>
#include <cstdlib>

using namespace std;

bool next_permutation(int *arr, int num);
void print(int *arr, int num);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out num" << endl;
        return 1;
    }

    int num = atoi(argv[1]);
    int *arr = new int[num];

    for (int i = 0; i < num; ++i)
        arr[i] = i+1;

    print(arr, num);

    while (next_permutation(arr, num))
        print(arr, num);

    return 0;
}

bool next_permutation(int *arr, int num)
{
    int pos;
    for (pos = num - 1; (pos > 0) && (arr[pos] < arr[pos-1]); --pos);

    if (pos == 0)
        return false;

    int idx;
    for (idx = num - 1; arr[idx] < arr[pos-1]; --idx);

    int tmp = arr[pos-1];
    arr[pos-1] = arr[idx];
    arr[idx] = tmp;

    for (idx = num - 1; pos < idx; ++pos, --idx)
    {
        tmp = arr[pos];
        arr[pos] = arr[idx];
        arr[idx] = tmp;
    }

    return true;
}

void print(int *arr, int num)
{
    for (int i = 0; i < num; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}
