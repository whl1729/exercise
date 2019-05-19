#include <iostream>

using namespace std;

struct A
{
    A() {}
    virtual ~A() {}
    int a = 1;
};

struct B : public A
{
    B() {}
    virtual ~B() {}
    int b = 2;
};

struct C : public B
{
    C() {}
    virtual ~C() {}
    int c = 3;
};

struct D : public B, public A
{
    D() {}
    virtual ~D() {}
    int d = 4;
};

int main()
{
    A *pa = new C;
    B *pb = dynamic_cast<B*>(pa);
    cout << "cast A to B " << (pb ? "succeed" : "fail") << endl;
    
    pb = new B;
    C *pc = dynamic_cast<C*>(pb);
    cout << "cast B to C " << (pc ? "succeed" : "fail") << endl;
    delete pc;

    if (C *pc = dynamic_cast<C*>(pa))
    {
        cout << "c=" << pc->c << endl;
    }
    else
    {
        cout << "a=" << pa->a << endl;
    }
//    pa = new D;
//    pb = dynamic_cast<B*>(pa);

    return 0;
}
