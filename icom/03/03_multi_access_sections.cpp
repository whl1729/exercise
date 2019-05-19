#include <iostream>

using namespace std;

class Foo
{
    char a;
    char b;
    char c;
    char d;
};

class Bar
{
public:
    char a;
protected:
    char b;
private:
    char c;
    char d;
};

class Cat
{
public:
    int a;
    char ch[2];
private:
    char zh[2];
    int b;
};

class Dog
{
private:
    int a;
    char ch[2];
public:
    char zh[2];
    int b;
};

int main()
{
    cout << "sizeof Foo yielded " << sizeof(Foo) << endl;
    cout << "sizeof Bar yielded " << sizeof(Bar) << endl;
    cout << "sizeof Cat yielded " << sizeof(Cat) << endl;
    cout << "sizeof Dog yielded " << sizeof(Dog) << endl;

    return 0;
}
