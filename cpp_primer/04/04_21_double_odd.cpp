#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;

    for (int pos = 0; pos < 10; pos++)
        vi.push_back(pos);

    for (auto &v : vi)
        v = (v % 2) ? (2 * v) : v;

    for (auto v: vi)
        cout << v << ' ';
    cout << endl;

    return 0;
}
