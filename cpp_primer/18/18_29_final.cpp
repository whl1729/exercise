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
    Base() { cout << "Base()" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class D1 : virtual public Base
{
public:
    D1() { cout << "D1()" << endl; }
    ~D1() { cout << "~D1()" << endl; }
};

class D2 : virtual public Base
{
public:
    D2() { cout << "D2()" << endl; }
    ~D2() { cout << "~D2()" << endl; }
};

class MI : public D1, public D2
{
public:
    MI() { cout << "MI()" << endl; }
    ~MI() { cout << "~MI()" << endl; }
};

class Final : public MI, public Class
{
public:
    Final() { cout << "Final()" << endl; }
    ~Final() { cout << "~Final()" << endl; }
};

int main()
{
    // Exercise 18.29 (a)
    Final *pf = new Final;
    cout << endl;
    delete pf;

    // Exercise 18.29 (c)
    Base *pb;
    Class *pc;
    MI *pmi;
    D2 *pd2;

    // error: invalid conversion from ‘Class*’ to ‘Base*’ [-fpermissive]
    // pb = new Class;
    // error: ‘Class’ is an ambiguous base of ‘Final’
    // pc = new Final;
    // error: invalid conversion from ‘Base*’ to ‘MI*’
    // pmi = pb;
    pd2 = pmi;
    return 0;
}
