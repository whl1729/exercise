#ifndef __HASPTR_H__
#define __HASPTR_H__

#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()): 
        ps(new string(s)), i(0), use(new int(1)) { }
    HasPtr(const HasPtr &hp): ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
    ~HasPtr();
    HasPtr& operator=(const HasPtr& rhp);

    string get_str() { return *ps; }
    string set_str(string str) { *ps = str; }
    int get_use() { return *use; }
    void print(const string &s);

private:
    string *ps;
    int i;
    int *use;
};

HasPtr::~HasPtr() 
{
    if (--*use == 0)
    {
        delete ps; 
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& rhp)
{
    ++*rhp.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }

    ps = rhp.ps;
    i = rhp.i;
    use = rhp.use;

    return *this;
}

void HasPtr::print(const string &s)
{
    cout << s << ": " << *ps << ", " << *use << endl;
}
#endif
