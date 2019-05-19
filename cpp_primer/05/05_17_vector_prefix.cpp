#include <iostream>
#include <vector>

using namespace std;

bool is_prefix(vector<int> &vec1, vector<int> &vec2);

int main()
{
    vector<int> vec1, vec2;
    int num;

    cout << "Enter vector 1's elements(End with 0): " << endl;
    while (cin >> num && num)
        vec1.push_back(num);

    cout << "Enter vector 2's elements(End with 0): " << endl;
    while (cin >> num && num)
        vec2.push_back(num);

    cout << (is_prefix(vec1, vec2) ? "true" : "false") << endl;

    return 0;
}

bool is_prefix(vector<int> &vec1, vector<int> &vec2)
{
    for (int pos = 0; pos < vec1.size() && pos < vec2.size(); pos++)
    {
        if (vec1[pos] != vec2[pos])
            return false;
    }

    return true;
}
