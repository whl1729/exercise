#include <iostream>
#include <thread>

using namespace std;

void delay(int ticks)
{
    for (int i = 0; i < ticks; ++i)
        ;
}

void foo()
{
    while (true)
    {
        cout << "Let's study..." << endl;
        delay(1000000);
    }
}

void bar()
{
    while (true)
    {
        cout << "Let's sleep..." << endl;
        delay(1000000);
    }
}

int main()
{
    thread first{foo};
    thread second{bar};

    first.join();
    second.join();

    return 0;
}
