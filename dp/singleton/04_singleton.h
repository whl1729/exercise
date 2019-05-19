#include <iostream>

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
        cout << "BSingleton::getInstance()" << endl;
        cout << m_data << " " << flag << endl;
        if (flag)
        {
            cout << "m_data = new BSingleton;" << endl;
            m_data = new BSingleton;
            flag = 0;
        }
        return m_data;
    }
    void do_something()
    {
        cout << "BSingleton do_something!" << endl;
    }
protected:
    static BSingleton *m_data; //static data member            
    static int flag;
    BSingleton();
    ~BSingleton() {}
};
