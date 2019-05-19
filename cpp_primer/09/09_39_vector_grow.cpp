#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;

    cout << vi.capacity() << endl;

    for (int num = 1; num < 100; ++num)
    {
        vi.push_back(num);
        cout << num << ' ' << vi.capacity() << endl;
    }

    vi.shrink_to_fit();

    cout << vi.capacity() << endl;

    vi.reserve(1000);

    cout << vi.capacity() << endl;

    return 0;
}
