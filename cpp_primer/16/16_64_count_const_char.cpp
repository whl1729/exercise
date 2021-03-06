#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
int count_elem(const vector<T> &vec, T val)
{
    int cnt = 0;
    for (auto &v : vec)
        if (v == val)
            ++cnt;
    return cnt;
}

template <>
int count_elem(const vector<const char *> &vec, const char *val)
{
    int cnt = 0;
    for (auto &v : vec)
        if (v == val)
            ++cnt;
    return cnt;
}

int main()
{
    vector<int> ivec{1,2,3,2,1,3,4,5,6,2,3};
    vector<double> dvec{1.2, 2.3, 3.4, 4.5};
    vector<string> svec{"hi", "hey", "hello", "hi"};
    vector<const char*> cvec{"well", "good", "nice", "not bad"};

    cout << "1 occurs " << count_elem(ivec, 1) << " time(s)." << endl;
    cout << "3.14 occurs " << count_elem(dvec, 3.14) << " time(s)." << endl;
    cout << "\"hello\" occurs " << count_elem(svec, string("hello")) << " time(s)." << endl;
    cout << "\"nice\" occurs " << count_elem(cvec, "nice") << " time(s)." << endl;

    return 0;
}
