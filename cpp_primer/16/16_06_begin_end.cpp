#include <iostream>

using namespace std;

template <typename T, unsigned size>
T* begin_of(T (&arr)[size])
{
    return arr;
}

template <typename T, unsigned size>
T* end_of(T (&arr)[size])
{
    return arr + size;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    string srr[] = {"Just", "the", "way", "you", "are", "see", "you", "again"};

    cout << *begin_of(arr) << " " << *(end_of(arr) - 1) << endl;
    cout << *begin_of(srr) << " " << *(end_of(srr) - 1) << endl;
}
