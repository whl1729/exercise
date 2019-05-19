#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

int main()
{
    map<string, vector<pair<string, Date>>> family;
    string last, child;
    Date birth;

    cout << "Enter family's last name, the child's name and birthday: " << endl;

    while (cin >> last >> child >> birth.year >> birth.month >> birth.day)
    {
        family[last].push_back(pair<string, Date>(child, birth));
    }

    for (auto &f : family)
    {
        cout << f.first << " : " << endl;

        for (auto &s : f.second)
            cout << s.first << ' ' << s.second.year << '/' 
                 << s.second.month << '/' << s.second.day << endl;
    }

    return 0;
}
