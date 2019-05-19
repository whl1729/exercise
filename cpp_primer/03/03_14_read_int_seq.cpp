#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    int num;

    while (cin >> num)
        vi.push_back(num);

    for (auto v : vi)
        cout << v << ' ';

    cout << endl;

    return 0;
}
