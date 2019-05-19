#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    return *beg;
}

int main()
{
    vector<int> ivec{1,2,3};
    vector<string> svec{"hello", "world"};

    cout << fcn3(ivec.begin(), ivec.end()) << endl;
    //cout <<fcn3(svec.begin(), svec.end()) << endl;

    return 0;
}
