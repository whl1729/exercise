#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<double> dvec{1.1, 2.2, 3.14};

    cout << accumulate(dvec.cbegin(), dvec.cend(), 0.0) << endl;

    return 0;
}
