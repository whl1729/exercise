#include <iostream>
#include <random>
#include <ctime>

using namespace std;

unsigned uniform(unsigned see = 0, unsigned min = 1, unsigned max = 2147483646)
{
    static default_random_engine eng(see);
    static uniform_int_distribution<unsigned> uni(min, max);
    return uni(eng);
}

int main()
{
    for (int i = 0; i < 10; ++i)
        cout << uniform(time(0), 1, 100) << endl;

    return 0;
}
