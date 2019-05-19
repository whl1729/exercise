#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    vector<pair<string, int>> people;
    pair<string, int> someone;

    cout << "Enter peoples' name and age: " << endl;

    while (cin >> someone.first >> someone.second)
        people.push_back(someone);

    for (auto &p : people)
        cout << p.first << ' ' << p.second << endl;

    return 0;
}
