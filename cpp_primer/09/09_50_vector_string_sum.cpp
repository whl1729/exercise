#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string num;
    vector<string> vs;

    cout << "Enter integers: " << endl;
    while (cin >> num)
        vs.push_back(num);

    cin.clear();

    long sum = 0;

    for (auto &s: vs)
        sum += stol(s);

    cout << sum << endl;

    cout << "Enter floating-point numbers: " << endl;

    vs.clear();

    while (cin >> num)
        vs.push_back(num);

    double dsum = 0;

    for (auto &s: vs)
        dsum += stod(s);

    cout << dsum << endl;

    return 0;
}
