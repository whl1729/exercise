#include <iostream>
#include <thread>

using namespace std;

int data;

void foo()
{
    ++data;
    cout << data << endl;
}

int main()
{
    thread first(foo);
    thread second(foo);

    first.join();
    second.join();

    return 0;
}
