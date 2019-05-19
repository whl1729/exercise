#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main()
{
    vector<int> factors;
    int num, fact;

    cout << "Enter a num: " << endl;
    cin >> num;

    cout << "Enter vectors's elements: " << endl;
    while (cin >> fact)
        factors.push_back(fact);

    auto iter = find_if_not(factors.begin(), factors.end(), 
                            bind(modulus<int>(), num, _1));

    cout << ((iter == factors.end()) ? "not found" : to_string(*iter)) << endl;

    return 0;
}
