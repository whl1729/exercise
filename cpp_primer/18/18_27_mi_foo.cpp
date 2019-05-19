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
    Derived(): sval("No Complaint, I can manage.") {}
    void print(std::string str) const { cout << str << endl; }
protected:
    std::string sval;
    double dval = 9.42;
};

struct MI : public Derived, public Base2
{
    void print(std::vector<double> vd) const
    {
        cout << "{";
        for (auto d : vd)
            cout << d << " ";
        cout << "}" << endl;
    }
    void foo(double cval);
protected:
    int *ival;
    std::vector<double> dvec;
};

void MI::foo(double cval)
{
    int dval = 4;

    // Exercise 18.27 (b)
    cout << "dval=" << dval << endl;
    cout << "cval=" << cval << endl;
    cout << "ival=" << ival << endl;
    cout << "dvec=";
    print(dvec);
    cout << "fval=" << fval << endl;
    cout << "sval=" << sval << endl;

    // Exercise 18.27 (c)
    dval = Base1::dval + Derived::dval;
    cout << "dval=" << dval << endl;

    // Exercise 18.27 (d)
    dvec.push_back(Base2::fval);
    cout << "dvec=";
    print(dvec);

    // Exercise 18.27 (e)
    sval[0] = Base1::cval;
    cout << "sval=" << sval << endl;
}

int main()
{
    MI mi;
    mi.foo(12.56);
    return 0;
}
