#include <iostream>
#include <string>
#include <list>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>

using namespace std;
using chrono::steady_clock;
using chrono::milliseconds;

template <typename T>
class Sync_queue
{
public:
    void put(const T &val);
    void put(const T &val, steady_clock::duration d, int n);
    void get(T &val);
    void get(T &val, steady_clock::duration d);
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
void Sync_queue<T>::put(const T& val, steady_clock::duration d, int n)
{
    unique_lock<mutex> lck(mtx);
    bool not_full = cond.wait_for(lck, d, [this, n]{ return q.size() < n;});
    if (not_full)
    {
        q.push_back(val);
        cond.notify_one();
    }
    else
    {
        cond.notify_all();
        throw runtime_error("Sync_queue: put() timeout");
    }
}

template <typename T>
void Sync_queue<T>::get(T &val)
{
    unique_lock<mutex> lck(mtx);
    cond.wait(lck, [this]{return !q.empty(); });
    val = q.front();
    q.pop_front();
}

template <typename T>
void Sync_queue<T>::get(T &val, steady_clock::duration d)
{
    unique_lock<mutex> lck(mtx);
    bool not_empty = cond.wait_for(lck, d, [this]{return !q.empty(); });
    if (not_empty)
    {
        val = q.front();
        q.pop_front();
    }
    else
        throw runtime_error("Sync_queue: get() timeout");
}

Sync_queue<string> mq;

void producer()
{
    string data;
    while (true)
    {
        cin >> data;
        if (!cin) break;
        mq.put(data, milliseconds{2000}, 5);
    }
}

void consumer()
{
    while (true)
    {
        string m;
        mq.get(m, milliseconds{20000});
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
