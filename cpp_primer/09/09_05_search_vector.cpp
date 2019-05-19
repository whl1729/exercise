#include <iostream>
#include <vector>

using namespace std;
using iter = vector<int>::iterator;

iter search(iter begin, iter end, int target)
{
    for (; begin != end; ++begin)
        if (*begin == target)
            return begin;

    return end;
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
    cout << (search(vi.begin(), vi.end(), num) == vi.end() ? "not found" : "found") << endl;

    return 0;
}
