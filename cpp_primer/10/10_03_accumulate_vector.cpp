#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;

    for (int num = 1; num < 100; ++num)
        vi.push_back(num);

    cout << "sum=" << accumulate(vi.cbegin(), vi.cend(), 0) << endl;

    return 0;
}
