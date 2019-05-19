#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int val;
    vector<int> ivec;

    cout << "Enter vector's elements: " << endl;
    while (cin >> val)
        ivec.push_back(val);

    cin.clear();
    cout << "Enter a target: " << endl;
    cin >> val;

    cout <<  "The target occurs " << count(ivec.cbegin(), ivec.cend(), val)
         << " times." << endl;

    return 0;
}
