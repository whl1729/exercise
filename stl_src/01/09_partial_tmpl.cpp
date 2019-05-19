#include <iostream>

using std::cout;
using std::endl;

#define __STL_TEMPLATE_NULL template<>

template <class Key> struct hash
{
    void operator()() { cout << "hash<T>" << endl; }
};

//template <> struct hash<char>
__STL_TEMPLATE_NULL struct hash<char>
{
    void operator()() { cout << "hash<char>" << endl; }
};

//template <> struct hash<unsigned char>
__STL_TEMPLATE_NULL struct hash<unsigned char>
{
    void operator()() { cout << "hash<unsigned char>" << endl; }
};

int main()
{
    hash<long> t1;
    hash<char> t2;
    hash<unsigned char> t3;

    t1();
    t2();
    t3();

    return 0;
}
