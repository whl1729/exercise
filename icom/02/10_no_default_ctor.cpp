#include <iostream>

using namespace std;

class Foo
{
public:
    void print() const 
    { 
        cout << "num=" << num << endl; 
        cout << "ptr=" << ptr << endl;
        for (int i = 0; i < 5; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
private:
    int num;
    char *ptr;
    double arr[5];
};

int main()
{
    Foo foo;
    foo.print();
    return 0;
}
