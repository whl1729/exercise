#include <iostream>

using namespace std;

class Y;

class X
{
public:
    X() = default;
    const string &get_name() const { return name; }
    void set_partner(Y* parnter) { y = parnter; }
    Y *get_partner() { return y; }
private:
    string name = "x";
    Y *y;
};

class Y
{
public:
    Y() = default;
    const string &get_name() const { return name; }
    void set_partner(X* parnter) { x = parnter; }
    X *get_partner() { return x; }
private:
    string name = "y";
    X *x;
};

int main()
{
    X x;
    Y y;
    x.set_partner(&y);
    y.set_partner(&x);

    cout << x.get_name() << " " << x.get_partner()->get_name() << endl;
    cout << y.get_name() << " " << y.get_partner()->get_name() << endl;

    return 0;
}
