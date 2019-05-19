#include <iostream>

using namespace std;

void swap(int &foo, int &bar)
{
    foo = foo + bar;
    bar = foo - bar;
    foo = foo - bar;
}

int main()
{
    int foo, bar;
    
    cout << "Enter two numbers: " << endl;
    cin >> foo >> bar;
    cout << "before swapping, foo=" << foo << " bar=" << bar << endl;

    swap(foo, bar);

    cout << "after swapping , foo=" << foo << " bar=" << bar << endl;

    return 0;
}
