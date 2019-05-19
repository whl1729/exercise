#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> simap;
    simap[string("jjhou")] = 1;
    simap[string("jerry")] = 2;
    simap[string("jason")] = 3;
    simap[string("jimmy")] = 4;

    pair<string, int> value(string("david"), 5);
    simap.insert(value);

    for (auto iter = simap.begin(); iter != simap.end(); ++iter)
        cout << iter->first << " " << iter->second << endl;

    cout << simap[string("jjhou")] << endl;

    auto iter = simap.find(string("mchen"));
    if (iter == simap.end())
        cout << "mchen not found" << endl;

    iter = simap.find(string("jerry"));
    if (iter != simap.end())
        cout << "jerry found" << endl;

    iter->second = 9;
    cout << simap[string("jerry")] << endl;

    return 0;
}
