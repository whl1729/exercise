#include <iostream>

using namespace std;

class A
{
public:
    A() {}
    virtual ~A() {}
};

class B : public A
{
public:
    B() {}
    virtual ~B() {}
};

class C : public B
{
public:
    C() {}
    virtual ~C() {}
};

int main()
{
    A *pa = new C;
    cout << typeid(pa).name() << endl;

    C cobj;
    A &ra = cobj;
    cout << typeid(&ra).name() << endl;

    B *px = new B;
    A &rx = *px;
    cout << typeid(rx).name() << endl;

    return 0;
}
