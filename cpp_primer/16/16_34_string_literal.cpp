#include <string>

template <class T> 
int compare(const T &lhs, const T &rhs)
{
    if (lhs < rhs) return -1;
    if (rhs < lhs) return 1;
    return 0;
}

int main()
{
    compare("bye", "dad");
    compare<std::string>("hi", "world");
    return 0;
}
