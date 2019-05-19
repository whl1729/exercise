#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t << endl;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

int main()
{
    vector<string> vs{"Never", "Give", "Up"};
    print(cout, vs);

    return 0;
}
