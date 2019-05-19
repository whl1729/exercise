#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "HasPtr.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<HasPtr> vh;
    string word;
    int num;

    cout << "Enter some HasPtr: " << endl;
    while (cin >> word >> num)
        vh.emplace_back(word, num);

    sort(vh.begin(), vh.end());

    for (auto &h: vh)
        h.print();

    return 0;
}
