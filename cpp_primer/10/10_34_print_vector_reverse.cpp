#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> vi;
    int num;

    cout << "Enter vector's number: " << endl;
    while (cin >> num)
        vi.push_back(num);

    for (auto rbeg = vi.crbegin(); rbeg != vi.crend(); ++rbeg)
        cout << *rbeg << ' ';
    cout << endl;

    return 0;
}
