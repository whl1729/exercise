#include <iostream>

using namespace std;

class Base1
{
public:
    Base1() = default;
    virtual void print() { cout << "Base1" << endl; }
    virtual ~Base1() { cout << "~Base1()" << endl; }
};

class Base2
{
public:
    Base2() = default;
    virtual void print() { cout << "Base2" << endl; }
    virtual ~Base2() { cout << "~Base2()" << endl; }
};

class D1: public Base1
{
public:
    D1() = default;
    virtual void print() { cout << "D1" << endl; }
    virtual ~D1() { cout << "~D1()" << endl; }
};

class D2: public Base2
{
public:
    D2() = default;
    virtual void print() { cout << "D2" << endl; }
    virtual ~D2() { cout << "~D2()" << endl; }
};

class MI: public D1, public D2
{
public:
    MI() = default;
    virtual void print() { cout << "MI" << endl; }
    virtual ~MI() { cout << "~MI()" << endl; }
};

int main()
{
    Base1 *pb1 = new MI;
    Base2 *pb2 = new MI;
    D1 *pd1 = new MI;
    D2 *pd2 = new MI;

    pb1->print();
    pb2->print();
    pd1->print();
    pd2->print();
    delete pb1;
    cout << "delete pb1 finished" << endl;
    delete pb2;
    cout << "delete pb2 finished" << endl;
    delete pd1;
    cout << "delete pd1 finished" << endl;
    delete pd2;
    cout << "delete pd2 finished" << endl;
    return 0;
}
