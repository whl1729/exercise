#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<unsigned> bad_randVec()
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}

int main()
{
    vector<unsigned> v1(bad_randVec());
    vector<unsigned> v2(bad_randVec());

    cout << ((v1 == v2) ? "equal" : "not equal") << endl;

    return 0;
}
