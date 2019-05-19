#include <iostream>

using namespace std;

class Foo
{
public:
    static int num;
};

int Foo::num = 1729;

int main()
{
    cout << "Foo::num=" << Foo::num << endl;

    Foo foo;
    cout << "foo.num=" << foo.num << endl;

    foo.num = 1024;
    cout << "Foo::num=" << Foo::num << endl;
    cout << "foo.num=" << foo.num << endl;

    Foo::num = 2048;
    cout << "Foo::num=" << Foo::num << endl;
    cout << "foo.num=" << foo.num << endl;

    return 0;
}
