#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    queue<int, list<int>> iqueue;

    for (int i = 0; i < 4; ++i)
        iqueue.push(2*i+1);

    cout << iqueue.size() << endl;
    cout << iqueue.front() << endl;

    for (int i = 0; i< 3; ++i)
    {
        iqueue.pop();
        cout << iqueue.front() << " " << iqueue.back() << endl;
    }

    cout << iqueue.size() << endl;

    return 0;
}
