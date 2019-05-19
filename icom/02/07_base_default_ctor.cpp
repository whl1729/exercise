#include <iostream>

using namespace std;

class Foo
{
public:
//    Foo() { cout << "Foo()" << endl; }
//    Foo(int i): num(i) { cout << "Foo(" << i << ")" << endl; }
    int get() const { return num; }
private:
    int num;
};

class Bar : public Foo
{
public:
    Bar() { cout << "Bar()" << endl; }
//    Bar(int i): cnt(i) {}
private:
    int cnt;
};

int main()
{
    Bar bar;
//    Bar bar(1024);
    cout << "num: " << bar.get() << endl;
    return 0;
}
