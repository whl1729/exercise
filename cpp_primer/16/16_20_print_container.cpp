#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename T>
void print(const T &t)
{
    for (auto &elem : t)
        cout << elem << " ";
    cout << endl;
}

int main()
{
    vector<int> ivec{1, 1, 2, 3, 5, 8, 13, 21, 34};
    list<string> slist{ "like", "the", "blue", "bird", "flying", "by", "me"};
    print(ivec);
    print(slist);

    return 0;
}
