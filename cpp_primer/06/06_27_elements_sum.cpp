#include <iostream>
#include <vector>

using namespace std;

int sum(initializer_list<int> il)
{
    int sum = 0;

    for (auto beg = il.begin(); beg != il.end(); ++beg)
        sum += *beg;

    return sum;
}

int main()
{
    initializer_list<int> il{1,2,3,4,5};

    cout << "sum: " << sum(il) << endl;

    return 0;
}
