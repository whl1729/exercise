#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    default_random_engine e1;
    default_random_engine e2(e2.max());
    default_random_engine e3;
    e3.seed(32767);
    default_random_engine e4(32767);
    default_random_engine e5(time(0));
    cout << "time: " << time(0) << endl;

    for (size_t i = 0; i != 10; ++i)
    {
        cout << e5() << " ";
        if (e1() == e2())
            cout << "unseeded match at iteration: " << i << endl;
        if (e3() != e4())
            cout << "seeded differs at iteration: " << i << endl;
    }

    cout << endl;

    return 0;
}
