#include <iostream>

using namespace std;

class Class
{
public:
    Class() { cout << "Class()" << endl; }
    ~Class() { cout << "~Class()" << endl; }
};

class Base : public Class
{
public:
    Base() : num(0) { cout << "Base()" << endl; }
    Base(const Base &b) : num(b.num) { }
    Base(int i) : num(i) { }
    ~Base() { cout << "~Base()" << endl; }
    void print() { cout << "num: " << num << endl; }
protected:
    int num;
};

class D1 : virtual public Base
{
public:
    D1() { cout << "D1()" << endl; }
    D1(const D1 &d) : Base(d) { }
    D1(int i) : Base(i) { }
    ~D1() { cout << "~D1()" << endl; }
};

class D2 : virtual public Base
{
public:
    D2() { cout << "D2()" << endl; }
    D2(const D2 &d) : Base(d) { }
    D2(int i) : Base(i) { }
    ~D2() { cout << "~D2()" << endl; }
};

class MI : public D1, public D2
{
public:
    MI() { cout << "MI()" << endl; }
    MI(const MI &m) : Base(m) { }
    MI(int i) : Base(i) { }
    ~MI() { cout << "~MI()" << endl; }
};

class Final : public MI, public Class
{
public:
    Final() { cout << "Final()" << endl; }
    Final(const Final &f) : Base(f) { }
    Final(int i) : Base(i) { }
    ~Final() { cout << "~Final()" << endl; }
};

int main()
{
    // Exercise 18.29 (a)
    Final *pf1 = new Final();
    cout << endl;
    Final f2(1729);
    cout << endl;
    Final f3(f2);
    cout << endl;

    pf1->print();
    f2.print();
    f3.print();

    delete pf1;

    return 0;
}
