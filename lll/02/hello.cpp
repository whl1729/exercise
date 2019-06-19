#include <iostream>

using namespace std;

class Hello
{
public:
    Hello() 
    {
        data = new int(100);
        cout << "Hello World! " << *data << endl; 
    }
    ~Hello()
    {
        if (data)
            delete data;
    }

private:
    int *data;
};

Hello hi;

int main()
{
    int foo = 425;
    int bar = 620;
    cout << foo + bar << endl;
    return 0;
}
