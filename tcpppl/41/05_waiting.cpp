#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    auto t0 = high_resolution_clock::now();
    this_thread::sleep_for(milliseconds{20});
    auto t1 = high_resolution_clock::now();
    cout << duration_cast<nanoseconds>(t1-t0).count() << " nanoseconds passed\n";

    return 0;
}
