#include <iostream>
#include <string>

using namespace std;

template<typename T>
void print(const T arr[], size_t sz)
{
    for (size_t pos = 0; pos < sz; ++pos)
        cout << arr[pos] << " ";
    cout << endl;
}

int main()
{
    int irr[] = {1, 2, 3, 4, 5};
    double drr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    string srr[] = {"I", "wanna", "be", "free"};

    print(irr, 5);
    print(drr, 5);
    print(srr, 4);

    cout << endl;

    return 0;
}
