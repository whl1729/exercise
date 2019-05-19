#include <iostream>
#include <fstream>

using namespace std;

class Foo
{
public:
    Foo() { cout << "Foo()" << endl; }
    ~Foo() { cout << "~Foo()" << endl; }
};

class Bar
{
public:
    Bar() 
    {
        in.open("~/test/output");
        string line;
        getline(in, line);
        getline(in, line);
        cout << line << endl;
        cout << "Bar()" << endl; 

    }
    ~Bar() { cout << "~Bar()" << endl; }
private:
    ifstream in;
};

void print()
{
    static Foo foo;
    cout << "Let's study C++" << endl;
}

int main()
{
    Bar *bar = new Bar();
    print();
    return 0;
}
