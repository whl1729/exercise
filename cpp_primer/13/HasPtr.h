#ifndef __HASPTR_H__
#define __HASPTR_H__

#include <string>

using std::string;
using std::cout;
using std::endl;

class HasPtr
{
friend void swap(HasPtr &lhs, HasPtr &rhs);

public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) { }
    HasPtr(const string &s = string(), int n = 0): ps(new string(s)), i(n) { }
    HasPtr(const HasPtr &hp): ps(new string(*hp.ps)), i(hp.i) { }
    ~HasPtr() { delete ps; }
    HasPtr& operator=(const HasPtr &rhp)
    {
        *ps = *rhp.ps;
        i = rhp.i;
        return *this;
    }
    bool operator<(const HasPtr &rhp)
    {
        return i < rhp.i;
    }

    void swap(HasPtr &rhs)
    {
        cout << "swap: lhs(" << *ps << ", " << i 
             << "), rhs(" << *rhs.ps << ", " << rhs.i << ")" << endl;

        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
    }
    string get_str() { return *ps; }
    string set_str(string str) { *ps = str; }
    void print(const string &s = string()) { cout << s << *ps << " " << i << endl; }

private:
    string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs)
{
    lhs.swap(rhs);
}

#endif
