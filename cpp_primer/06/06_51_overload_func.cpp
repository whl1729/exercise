#include <iostream>

using namespace std;

void print();
void print(int num);
void print(int foo, int bar);
void print(double foo, double bar = 3.14);

int main()
{
    //print(2.56, 42);
    print(42);
    print(42, 0 );
    print(2.56, 3.14);
    print(4.15);

    return 0;
}

void print()
{
    cout << "let it be." << endl;
}

void print(int num)
{
    cout << num << " is a nice number" << endl;
}

void print(int foo, int bar)
{
    cout << foo << " + " << bar << " = " << foo + bar << endl;
}

void print(double foo, double bar)
{
    cout << foo << " * " << bar << " = " << foo * bar << endl;
}

