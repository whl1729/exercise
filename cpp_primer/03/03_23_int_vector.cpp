#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    
    for (int pos = 0; pos < 10; pos++)
        vi.push_back(pos * pos);

    for (auto it = vi.begin(); it != vi.end(); it++)
    {
        cout << *it << ' ';
        *it = *it * 2;
    }

    cout << endl;

    for (auto it = vi.begin(); it != vi.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}
