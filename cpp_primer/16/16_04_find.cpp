#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <typename T, typename V>
T find_pos(T beg, T end, const V &val)
{
    for (auto cur = beg; cur != end; ++cur)
        if (*cur == val)
            return cur;
    return end;
}

int main()
{
    vector<int> ivec{1, 3, 5, 7, 9};
    list<string> slist{"apple", "banana", "cat", "dog", "egg"};

    cout << (find_pos(ivec.begin(), ivec.end(), 5) == ivec.end() ? "not found" : "found") << endl;
    cout << (find_pos(ivec.begin(), ivec.end(), 4) == ivec.end() ? "not found" : "found") << endl;
    cout << (find_pos(slist.begin(), slist.end(), "egg") == slist.end() ? "not found" : "found") << endl;
    cout << (find_pos(slist.begin(), slist.end(), "fly") == slist.end() ? "not found" : "found") << endl;

    return 0;
}
