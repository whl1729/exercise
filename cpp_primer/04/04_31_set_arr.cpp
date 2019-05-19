#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec(10);
    auto cnt = ivec.size();

    for (auto ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;

    for (auto iv : ivec)
        cout << iv << ' ';
    cout << endl;

    cnt = ivec.size();

    for (auto ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;

    for (auto iv : ivec)
        cout << iv << ' ';
    cout << endl;

    return 0;
}
