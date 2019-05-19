#include <iostream>
#include <string>
#include <list>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

template <typename T>
class Sync_queue
{
public:
    void put(const T &val);
    void get(T &val);
private:
    mutex mtx;
    condition_variable cond;
    list<T> q;
};

template <typename T>
void Sync_queue<T>::put(const T& val)
{
    lock_guard<mutex> lck(mtx);
    q.push_back(val);
    cond.notify_one();
}

template <typename T>
void Sync_queue<T>::get(T &val)
{
    unique_lock<mutex> lck(mtx);
    cond.wait(lck, [this]{return !q.empty(); });
    val = q.front();
    q.pop_front();
}

Sync_queue<string> mq;

void producer()
{
    string data;
    while (true)
    {
        cin >> data;
        if (!cin) break;
        mq.put(data);
    }
}

void consumer()
{
    while (true)
    {
        string m;
        mq.get(m);
        cout << m << endl;
    }
}

int main()
{
    thread t1{producer};
    thread t2{consumer};

    t1.join();
    t2.join();

    return 0;
}
