#include <iostream>
#include <random>

using namespace std;

int main()
{
    default_random_engine eng;
    uniform_real_distribution<double> urd(0,1);
    uniform_int_distribution<int> uid;

    for (size_t i = 0; i < 10; ++i)
        cout << urd(eng) << " ";
    cout << endl;

    for (size_t i = 0; i < 100; ++i)
        cout << uid(eng) << " ";
    cout << endl;

    return 0;
}
