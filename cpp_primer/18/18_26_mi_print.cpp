#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Base1
{
    void print(int i) const { cout << i << endl; }
protected:
    int ival = 1;
    double dval = 3.14;
    char cval = 'b';
private:
    int *id;
};

struct Base2
{
    void print(double d) const { cout << d << endl; }
protected:
    double fval = 6.28;
private:
    double dval = 62.8;
};

struct Derived : public Base1
{
    void print(std::string str) const { cout << str << endl; }
protected:
    std::string sval;
    double dval;
};

struct MI : public Derived, public Base2
{
    void print(std::vector<double> vd) const
    {
        for (auto d : vd)
            cout << d << " ";
        cout << endl;
    }
    void print(int i) const { Base1::print(i); }
protected:
    int *ival;
    std::vector<double> dvec;
};

int main()
{
    MI mi;
    mi.print(42);
    return 0;
}
