#include <iostream>

using namespace std;

template<typename T, unsigned size>
constexpr size_t size_of(const T(&)[size])
{
    return size;
}

int main()
{
    int arr[] = {1,4,9,16,25,36,49};
    cout << size_of(arr) << endl;

    return 0;
}
