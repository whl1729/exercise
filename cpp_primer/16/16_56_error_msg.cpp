#include <iostream>
#include <sstream>

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

template <typename T>
string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename... Args>
ostream &error_msg(ostream &os, const Args&... rest)
{
    return print(os, debug_rep(rest)...);
}

int main()
{
    error_msg(cout, "ok", 404, "warning", 3.14, "error", 'c');
    return 0;
}
