//   Crayondeng 
//   CSDN 
//   https://blog csdn net/crayondeng/article/details/24853471 
#include <iostream>

using namespace std;

class ASingleton
{
public:
    static ASingleton& getInstance();

    void do_something()
    {
        cout<<"ASingleton do_something!"<<endl;
    }
protected:
    ASingleton();
    ~ASingleton() {}
};

class BSingleton
{
public:
    static BSingleton& getInstance();

    void do_something()
    {
        cout<<"BSingleton do_something!"<<endl;
    }
protected:
    BSingleton();
    ~BSingleton() {}
};

ASingleton& ASingleton::getInstance()
{
    const BSingleton &b = BSingleton::getInstance();
    static ASingleton m_data;
    return m_data;
}

BSingleton& BSingleton::getInstance()
{
    const ASingleton &a = ASingleton::getInstance();
    static BSingleton m_data;
    return m_data;
}

ASingleton::ASingleton()
{
    cout<<"ASingleton constructor!"<<endl;
    //BSingleton::getInstance().do_something();
}

BSingleton::BSingleton()
{
    cout<<"BSingleton constructor!"<<endl;
}

int main()
{
    ASingleton::getInstance();

    return 0;
}
