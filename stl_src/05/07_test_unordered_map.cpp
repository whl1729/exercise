#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> days;

    days["January"] = 31;
    days["February"] = 28;
    days["March"] = 31;
    days["April"] = 30;
    days["May"] = 31;
    days["June"] = 30;
    days["July"] = 31;
    days["August"] = 30;
    days["September"] = 30;
    days["October"] = 31;
    days["November"] = 30;
    days["December"] = 31;

    cout << "September -> " << days["September"] << endl;
    cout << "June -> " << days["June"] << endl;
    cout << "February -> " << days["February"] << endl;
    cout << "December -> " << days["December"] << endl;

    for (auto iter = days.begin(); iter != days.end(); ++iter)
        cout << iter->first << ' ';
    cout << endl;

    return 0;
}
