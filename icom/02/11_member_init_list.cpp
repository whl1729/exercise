#include <iostream>

using namespace std;

class Bar
{
public:
    Bar() { cout << "Bar()" << endl; }
    Bar(int i): cnt(i) { cout << "Bar(" << i << ")" << endl; }
    Bar(const Bar &b): cnt(b.cnt)  { cout << "Bar(const Bar &b)" << endl; }
private:
    int cnt;
};

class Foo
{
public:
    Foo(): str("hello world")
    {
        bar = Bar(1024);
        num = 0;
    }
private:
    Bar bar;
    string str;
    int num;
};

int main()
{
    Foo foo;
    return 0;
}
