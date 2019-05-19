#include <iostream>

using namespace std;

void swap_ptr(int *&foo, int *&bar)
{
    int *tmp = foo;
    foo = bar;
    bar = tmp;
}

int main()
{
    int foo, bar;
    int *pear = &foo;
    int *apple = &bar;

    cout << "Enter two integers: " << endl;
    cin >> foo >> bar;
    cout << "*pear=" << *pear << "  *apple=" << *apple << endl;
    cout << "pear=" << (long)pear << "  apple=" << (long)apple << endl;
    
    swap_ptr(pear, apple);

    cout << "*pear=" << *pear << "  *apple=" << *apple << endl;
    cout << "pear=" << (long)pear << "  apple=" << (long)apple << endl;

    return 0;
}
