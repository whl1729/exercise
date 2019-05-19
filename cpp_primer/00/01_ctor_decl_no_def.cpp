// This program test what happens when we declare a copy constructor without definition.

#include <iostream>

using namespace std;

class Bar
{
public:
    Bar() {}
    void play();
};

class Foo
{
public:
    friend class Bar;
    Foo() {}
    Foo(const Foo&) = delete;
};

void Bar::play()
{
    cout << "Let's play football." << endl;
    Foo a;
    //Foo b = a;
}

int main()
{
    Bar bar;
    bar.play();

    return 0;
}
