#include <iostream>

using namespace std;

class Foo
{
public:
    Foo() { cout << "Foo()" << endl; }
    Foo(int i): num(i) { cout << "Foo(" << i << ")" << endl; }
    int get() const { return num; }
private:
    int num;
};

class Bar : public Foo
{};

int main()
{
    Bar bar;
    cout << "num: " << bar.get() << endl;
    return 0;
}
