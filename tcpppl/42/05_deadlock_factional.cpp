#include <iostream>
#include <mutex>

using namespace std;

recursive_mutex cout_mutex;
int result = 1;

void fact(int num)
{
    if (num != 1)
    {
        cout_mutex.lock();
        result *= num;
        fact(num-1);
        cout_mutex.unlock();
    }
}

int main()
{
    fact(10);
    cout << "10! = " << result << endl;
    return 0;
}
