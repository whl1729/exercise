#include <iostream>
#include <vector>

using namespace std;
using iter = vector<int>::iterator;

bool contains(iter begin, iter end, int target)
{
    for (; begin != end; ++begin)
        if (*begin == target)
            return true;

    return false;
}

int main()
{
    vector<int> vi;
    int num;

    cout << "Enter numbers: " << endl;

    while (cin >> num)
        vi.push_back(num);

    cin.clear();

    cout << "Enter target: " << endl;
    cin >> num;
    cout << (contains(vi.begin(), vi.end(), num) ? "found" : "not found") << endl;

    return 0;
}
