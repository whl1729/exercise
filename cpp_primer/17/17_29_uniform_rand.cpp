#include <iostream>
#include <random>
#include <ctime>

using namespace std;

unsigned uniform(unsigned see = 0)
{
    static default_random_engine eng(see);
    static uniform_int_distribution<unsigned> uni;
    return uni(eng);
}

int main()
{
    for (int i = 0; i < 10; ++i)
        cout << uniform(time(0)) << endl;

    return 0;
}
