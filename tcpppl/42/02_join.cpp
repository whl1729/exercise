#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void tick(int n)
{
    for (int i = 0; i != n; ++i)
    {
        this_thread::sleep_for(chrono::seconds{1});
        cout << "Alive!" << endl;
    }
}

int main()
{
    thread timer{tick, 10};
    timer.join();
    return 0;
}
