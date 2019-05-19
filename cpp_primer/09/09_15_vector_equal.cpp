#include <iostream>
#include <vector>

using namespace std;

bool equal(const vector<int> &foo, const vector<int> &bar)
{
    if (foo.size() != bar.size())
        return false;

    for (int pos = 0; pos < foo.size(); ++pos)
        if (foo[pos] != bar[pos])
            return false;

    return true;
}

int main()
{
    vector<int> ivec;
    vector<int> jvec;
    int num;

    cout << "Enter first vector: " << endl;

    while (cin >> num)
        ivec.push_back(num);

    cin.clear();

    cout << "Enter second vector: " << endl;

    while (cin >> num)
        jvec.push_back(num);

    cout << (equal(ivec, jvec) ? "equal" : "not equal") << endl;

    return 0;
}
