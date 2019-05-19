#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class CondEval
{
public:
    char operator()(bool yes, const char &a, const char& b) const 
        { return yes ? a : b; }
    int operator()(bool yes, const int &a, const int &b) const 
        { return yes ? a : b; }
    double operator()(bool yes, const double &a, const double &b) const 
        { return yes ? a : b; }
    string operator()(bool yes, const string &a, const string &b) const 
        { return yes ? a : b; }
};

int main()
{
    CondEval cond;
    int foo = 10, bar = 100;
    cout << "foo=10, bar=100, max=" << cond(foo > bar, foo, bar) << endl;
    char low = 'a', upp = 'A';
    cout << "low='a', upp='A', uppercase=" << cond(islower(low), upp, low) << endl;
    double pie = 3.14, eip = 4.13;
    cout << "pie=3.14, eip=4.13, min=" << cond(pie < eip, pie, eip) << endl;
    string egg = "egg", noodle = "noodle";
    cout << "egg, noodle, min=" << cond(egg < noodle, egg, noodle) << endl;

    return 0;
}
