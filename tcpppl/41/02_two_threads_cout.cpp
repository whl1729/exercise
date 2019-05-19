#include <iostream>
#include <thread>

using namespace std;

void foo()
{
    cout << "Hello " << endl;
}

void bar()
{
    cout << "Parallel World!\n";
}

int main()
{
    thread first{foo};
    thread second{bar};

    first.join();
    second.join();

    return 0;
}
