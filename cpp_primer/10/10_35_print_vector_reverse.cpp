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

    auto iter = vi.cend();
    while (--iter != vi.cbegin())
        cout << *iter << ' ';
    cout << *iter << endl;

    return 0;
}
