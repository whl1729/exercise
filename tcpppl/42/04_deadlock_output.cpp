#include <iostream>
#include <mutex>

using namespace std;

recursive_mutex cout_mutex;

template <typename Arg>
void write(Arg a)
{
    cout_mutex.lock();
    cout << a;
    cout_mutex.unlock();
}

template <typename Arg, typename... Args>
void write(Arg a, Args... tail)
{
    cout_mutex.lock();
    cout << a;
    write(tail...);
    cout_mutex.unlock();
}

int main()
{
    write("Hello ", "World!", " Hello ", "Tomorrow!");
    return 0;
}
