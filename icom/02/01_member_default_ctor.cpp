#include <iostream>

using namespace std;

class Foo
{
public:
    Foo(): num(1729) { cout << "Foo()" << endl; }
    Foo(int i): num(i) { cout << "Foo(int i)" << endl; }
    int get() { return num; }
private:
    int num;
};

class Bar
{
public:
    Foo foo;
    char *str;
};

int main()
{
    Bar bar;
    cout << bar.foo.get() << endl;
    cout << bar.str << endl;
    return 0;
}
