#include <iostream>

using namespace std;

class Foo
{
public:
    Foo() 
    { 
        data = new int(100);
        cout << "Foo()" << endl; 
    }

    ~Foo() 
    { 
        if (data) delete data;
        cout << "~Foo()" << endl; 
    }
private:
    int *data;
};

Foo foo;

int main()
{
    return 0;
}
