#include <iostream>
#include <vector>

using namespace std;

void insert_double(vector<int> &ivec, int target)
{
    auto iter = ivec.begin();
    auto mid = ivec.begin() + ivec.size() / 2;

    for (; iter != mid; --mid)
        if (*mid == target)
            mid = ivec.insert(mid, target * 2);
}

int main()
{
    vector<int> ivec;
    int num, target;

    cout << "Enter a vector: " << endl;
    while (cin >> num)
        ivec.push_back(num);

    cin.clear();

    cout << "Enter a target: " << endl;
    cin >> target;

    insert_double(ivec, target);

    for (auto i : ivec)
        cout << i << ' ';
    cout << endl;

    return 0;
}
