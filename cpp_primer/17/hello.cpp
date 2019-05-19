#include <iostream>
#include <random>

using namespace std;

int main()
{
    default_random_engine engine;
    cout << "min: " << engine.min() << " max: " << engine.max() << endl;

    uniform_int_distribution<unsigned> u(0, 9);
    for (size_t i = 0; i < 10; ++i)
        cout << u(engine) << " ";
    cout << endl;

    engine.seed(1729);
    engine.discard(5);
    for (size_t i = 0; i < 10; ++i)
        cout << engine() << " ";
    cout << endl;

    return 0;
}
