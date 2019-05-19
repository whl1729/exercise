#include <iostream>

using namespace std;

class X
{
public:
    int i;
    int j;
    X(int val): j(val), i(j) {}
};

class Y
{
public:
    int i;
    int j;
    Y(int val): j(val) { i = j; }
};

int main()
{
    X x(3);
    Y y(5);
    cout << "x.i=" << x.i << " x.j=" << x.j << endl;
    cout << "y.i=" << y.i << " y.j=" << y.j << endl;
    return 0;
}
