#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;
int data;

void foo()
{
    unique_lock<mutex> lck{m};
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
