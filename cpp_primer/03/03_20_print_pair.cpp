#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    int num, pos;
    int size, pair_num;

    while (cin >> num)
        vi.push_back(num);

    size = vi.size();
    pair_num = size / 2;

    for (pos = 0; pos < pair_num; pos++)
        cout << vi[2*pos] + vi[2*pos+1] << endl;

    if (size % 2)
        cout << vi[2*pos] << endl;

    cout << endl;

    for (pos = 0; pos < pair_num; pos++)
        cout << vi[pos] + vi[size-1-pos] << endl;

    if (size % 2)
        cout << vi[pos] << endl;

    return 0;
}
