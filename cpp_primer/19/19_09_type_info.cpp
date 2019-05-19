#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

class Base 
{
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base 
{
public:
    Derived() {}
    ~Derived() {}
};

int main()
{
    int arr[10];
    Derived d;
    Base *p = &d;
    cout << typeid(42).name() << ", "
         << typeid(arr).name() << ", "
         << typeid(Sales_data).name() << ", "
         << typeid(std::string).name() << ", "
         << typeid(d).name() << ", "
         << typeid(p).name() << ", "
         << typeid(*p).name() << endl;

    return 0;
}
