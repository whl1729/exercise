#include <iostream>
#include <random>

using namespace std;

unsigned uniform()
{
    static default_random_engine eng;
    static uniform_int_distribution<unsigned> uni;
    return uni(eng);
}

int main()
{
    for (int i = 0; i < 10; ++i)
        cout << uniform() << endl;

    return 0;
}
