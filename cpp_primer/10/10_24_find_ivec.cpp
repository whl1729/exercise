#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_size(int num, const string &str)
{
    return num > str.size();
}

int main()
{
    string word;
    int num;
    vector<int> vi;

    cout << "Enter a string: " << endl;
    cin >> word;

    cout << "Enter vector's elements: " << endl;
    while (cin >> num)
        vi.push_back(num);

    auto target = find_if(vi.begin(), vi.end(), 
                       bind(check_size, _1, word));

    cout << ((target == vi.end()) ? "not found" : to_string(*target)) << endl;

    return 0;
}
