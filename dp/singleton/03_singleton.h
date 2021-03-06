#include <iostream>
#include <string>

using namespace std;

class ASingleton
{
public:
    static ASingleton* getInstance()
    {
        return &m_data;
    }
    void do_something()
    {
        cout << "ASingleton do_something!" << endl;
    }
protected:
    static ASingleton m_data; //static data member            
    ASingleton();
    ~ASingleton() {}
};

class BSingleton
{
public:
    static BSingleton* getInstance()
    {
        return &m_data;
    }
    void do_something()
    {
        cout << "BSingleton do_something!" << endl;
        cout << *str << endl;
    }
protected:
    static BSingleton m_data; //static data member            
    string *str;
    BSingleton();
    ~BSingleton() {}
};
