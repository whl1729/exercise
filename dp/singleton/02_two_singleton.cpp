//   Crayondeng 
//   CSDN 
//   https://blog csdn net/crayondeng/article/details/24853471 
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
        cout<<"ASingleton do_something!"<<endl;
    }
protected:
    static ASingleton m_data; //static data member            
    ASingleton();
    ~ASingleton() {}
};

string *str;

class BSingleton
{
public:
    static BSingleton* getInstance()
    {
        return &m_data;
    }
    void do_something()
    {
        cout<<"BSingleton do_something!"<<endl;
        cout << *str << endl;
    }
protected:
    static BSingleton m_data; //static data member            
    BSingleton();
    ~BSingleton() {}
};

ASingleton ASingleton::m_data;
BSingleton BSingleton::m_data;

ASingleton::ASingleton()
{
    cout<<"ASingleton constructor!"<<endl;
    BSingleton::getInstance()->do_something();
}

BSingleton::BSingleton()
{
    str = new string("Hello world");
    cout<<"BSingleton constructor!"<<endl;
}

int main()
{
    return 0;
}
