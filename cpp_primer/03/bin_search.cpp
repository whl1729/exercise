#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    int num, pos;

    cout << "Enter numbers in order: " << endl;

    while (cin >> num && num != 0)
        vi.push_back(num);

    cout << "Enter number you want to find: " << endl;

    while (cin >> num)
    {
        auto beg = vi.begin();
        auto end = vi.end();
        auto mid = beg + (end - beg) / 2;

        while (mid != end && *mid != num)
        {
            if (num < *mid)
                end = mid;
            else
                beg = mid + 1;

            mid = beg + (end - beg) / 2;
        }

        pos = (mid == end) ? -1 : (mid - vi.begin());

        cout << pos << endl;
    }

    return 0;
}
