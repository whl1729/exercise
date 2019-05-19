#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, vector<string>> family;
    string last, child;

    cout << "Enter family's last name and the child's name: " << endl;

    while (cin >> last >> child)
    {
        family[last].push_back(child);
    }

    for (auto &f : family)
    {
        cout << f.first << " : ";

        for (auto &s : f.second)
            cout << s << ' ';
        cout << endl;
    }

    return 0;
}
