#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

struct X 
{
    int id;

    X(): id{++cnt} { cout << "X() for " << id << endl; }
    X(const X& x): id{++cnt} { cout << "X(const X&) for " << id << endl; }
    X& operator=(const X& x) { cout << "operator=() for " << id << endl; }
    ~X() { cout << "~X() for " << id << endl; }
};

void nonref(X a)
{
    cout << "run nonref function on X" << a.id << endl;
}

void ref(X &a)
{
    cout << "run ref function on X" << a.id << endl;
}

int main()
{
    X a;
    X b(a);
    X c = a;
    c = b;

    nonref(a);
    ref(b);

    X *d = new X;
    vector<X> e(10);

    delete d;

    return 0;
}
