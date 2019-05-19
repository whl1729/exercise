#include <iostream>

using namespace std;

struct Base
{
    void bar(int i) { cout << "Base::bar " << i << endl; }
protected:
    int ival = 1;
};

struct Derived1 : virtual public Base
{
    void bar(char c) { cout << "Derived1::bar " << c << endl; }
    void foo(char c) { cout << "Derived1::foo " << c << endl; }
protected:
    char cval = 'd';
};

struct Derived2 : virtual public Base
{
    void foo(int i) { cout << "Derived2::foo " << i << endl; }
protected:
    int ival = 3;
    char cval = 'e';
};

class VMI : public Derived1, public Derived2
{
public:
    void print()
    {
        cout << "ival=" << ival << endl;
        cout << "cval=" << Derived1::cval << endl;
        bar(100);
        Derived2::foo(200);
    }
};

int main()
{
    VMI vmi;
    vmi.print();
    return 0;
}
