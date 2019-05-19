#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx1;
mutex mtx2;

void task(mutex &m1, mutex &m2)
{
    unique_lock<mutex> lck1{m1};
    cout << "acquire mutex 1" << endl;
    unique_lock<mutex> lck2{m2};
    cout << "acquire mutex 2" << endl;
    cout << "finish task" << endl;
}

int main()
{
    thread t1{task, ref(mtx1), ref(mtx2)};
    thread t2{task, ref(mtx2), ref(mtx1)};

    t1.join();
    t2.join();

    return 0;
}
