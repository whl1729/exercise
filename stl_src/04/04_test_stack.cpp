#include <iostream>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    stack<int, list<int>> istack;
    
    for (int i = 0; i < 4; ++i)
        istack.push(2*i+1);

    cout << istack.size() << endl;
    cout << istack.top() << endl;

    for (int i = 0; i < 3; ++i)
    {
        istack.pop();
        cout << istack.top() << endl;
    }

    cout << istack.size() << endl;

    return 0;
}
