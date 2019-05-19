#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    multimap<string, string> family;
    string last, child;

    cout << "Enter family's last name and the child's name: " << endl;

    while (cin >> last >> child)
        family.insert(pair<string, string>(last, child));

    for (auto &f : family)
        cout << f.first << " : " << f.second << endl;

    return 0;
}
