#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned> scores(11, 0);
    auto it = scores.begin();
    unsigned grade;

    while (cin >> grade)
        if (grade <= 100)
            (*(it + grade/10))++;

    for (; it != scores.end(); it++)
        cout << *it << ' ';

    cout << endl;

    return 0;
}
