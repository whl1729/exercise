#include <iostream>
#include <vector>

using namespace std;

void print_arr(int *arr, int num);
void print_vec(vector<int> &vi);
bool is_equal_arr(int *arr, int *brr, int num);
bool is_equal_vec(vector<int> &avi, vector<int> &bvi);

int main()
{
    int arr[5] = {1,2,3,4,5};
    int brr[5] = {1,2,3,4,5};
    int crr[5] = {1,2,3,5,5};

    cout << "arr: ";
    print_arr(arr, 5);

    cout << "brr: ";
    print_arr(brr, 5);

    cout << "crr: ";
    print_arr(crr, 5);

    if (is_equal_arr(arr, brr, 5))
        cout << "arr is equal to brr" << endl;
    else
        cout << "arr is different to brr" << endl;

    if (is_equal_arr(arr, crr, 5))
        cout << "arr is equal to crr" << endl;
    else
        cout << "arr is different to crr" << endl;

    vector<int> avi;
    vector<int> bvi;
    vector<int> cvi;

    for (int pos = 0; pos < 5; pos++)
    {
        avi.push_back(arr[pos]);
        bvi.push_back(brr[pos]);
        cvi.push_back(crr[pos]);
    }

    cout << "avi: ";
    print_vec(avi);

    cout << "bvi: ";
    print_vec(bvi);

    cout << "cvi: ";
    print_vec(cvi);

    if (is_equal_vec(avi, bvi))
        cout << "avi is equal to bvi" << endl;
    else
        cout << "avi is different to bvi" << endl;

    if (is_equal_vec(avi, cvi))
        cout << "avi is equal to cvi" << endl;
    else
        cout << "avi is different to cvi" << endl;

}

void print_arr(int *arr, int num)
{
    for (int pos = 0; pos < num; pos++)
        cout << arr[pos] << ' ';
    cout << endl;
}

void print_vec(vector<int> &vi)
{
    for (auto v : vi)
        cout << v << ' ';
    cout << endl;
}

bool is_equal_arr(int *arr, int *brr, int num)
{
    for (int pos = 0; pos < num; pos++)
    {
        if (arr[pos] != brr[pos])
            return false;
    }

    return true;
}

bool is_equal_vec(vector<int> &avi, vector<int> &bvi)
{
    if (avi.size() != bvi.size())
        return false;

    for (auto av = avi.begin(), bv = bvi.begin(); av != avi.end() && bv != bvi.end(); av++, bv++)
    {
        if (*av != *bv)
            return false;
    }

    return true;
}

