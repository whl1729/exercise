#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T>
typename T::size_type min_len(const T &a, const T &b)
{
    return (a.size() < b.size() ? a.size() : b.size());
}

int main()
{
    cout << min_len(string("hello"), string("hi")) << endl;
    return 0;
}
