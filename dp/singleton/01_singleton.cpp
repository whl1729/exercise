#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton* Instance();
    int num = 0;
private:
    Singleton() {}
    static Singleton* _instance;
};

Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance()
{
    if (_instance == 0)
        _instance = new Singleton;

    return _instance;
}

int main()
{
    Singleton *foo = Singleton::Instance();
    cout << ++foo->num << endl;

    Singleton *bar = Singleton::Instance();
    cout << ++bar->num << endl;
    cout << foo->num << endl;
    cout << bar->num << endl;

    return 0;
}
