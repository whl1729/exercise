#include <iostream>

using namespace std;

struct A
{
    A() {}
    virtual ~A() {}
};

struct B : public A
{
    B() {}
    virtual ~B() {}
};

struct C : public B
{
    C() {}
    virtual ~C() {}
};

struct D : public B, public A
{
    D() {}
    virtual ~D() {}
};

int main()
{
    A *pa = new C;
    B *pb = dynamic_cast<B*>(pa);
    delete pb;
    cout << "cast A to B " << (pb ? "succeed" : "fail") << endl;
    
    pb = new B;
    C *pc = dynamic_cast<C*>(pb);
    cout << "cast B to C " << (pc ? "succeed" : "fail") << endl;
    delete pc;

//    pa = new D;
//    pb = dynamic_cast<B*>(pa);

    return 0;
}
