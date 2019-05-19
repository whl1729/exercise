#include <iostream>
#include <string>

using namespace std;

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

template <typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t << endl;
}

int main()
{
    int i = 620;
    double d = 3.14;
    string word = "Long time no see";
    //print(cout, i);
    //print(cout, i, d);
    print(cout, i, 'I', d);
    print(cout, i, d, word, "2019");
    print(cout, i, d, word, "2019", 1.732);

    return 0;
}
