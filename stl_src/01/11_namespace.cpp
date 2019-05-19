#include <iostream>

namespace whl
{
    int foo = 5;
    class Bar 
    {
        Bar() { std::cout << "whl::Bar" << std::endl; }
    };
}

using namespace whl;

template <class T>
class Bar
{
    Bar() { std::cout << "::Bar<T>" << std::endl; }
};

//template <> class Bar<int>
//{
//    Bar() { std::cout << "::Bar<int>" << std::endl; }
//}

//int foo = 1;

int main()
{
//    std::cout << foo << std::endl;
    std::cout << ::foo << std::endl;
    std::cout << whl::foo << std::endl;

//    Bar bar;

    return 0;
}
