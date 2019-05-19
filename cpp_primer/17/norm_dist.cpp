#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    default_random_engine eng(time(0));
    normal_distribution<> norm(4, 1.5);
    vector<unsigned> vals(9);
    for (size_t i = 0; i != 200; ++i)
    {
        unsigned v = lround(norm(eng));
        if (v < vals.size())
            ++vals[v];
    }

    for (size_t j = 0; j != vals.size(); ++j)
        cout << j << ": " << string(vals[j], '*') << endl;
}
