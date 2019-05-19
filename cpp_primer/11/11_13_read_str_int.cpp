#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void read_people_1()
{
    vector<pair<string, int>> people;
    pair<string, int> someone;

    cout << "Enter peoples' name and age: " << endl;

    while (cin >> someone.first >> someone.second)
        people.push_back(someone);

    cin.clear();
    for (auto &p : people)
        cout << p.first << ' ' << p.second << endl;
}

void read_people_2()
{
    vector<pair<string, int>> people;
    string name;
    int age;

    cout << "Enter peoples' name and age: " << endl;

    while (cin >> name >> age)
        people.push_back(pair<string, int>(name, age));

    cin.clear();
    for (auto &p : people)
        cout << p.first << ' ' << p.second << endl;
}

void read_people_3()
{
    vector<pair<string, int>> people;
    string name;
    int age;

    cout << "Enter peoples' name and age: " << endl;

    while (cin >> name >> age)
    {
        pair<string, int> someone = {name, age};
        people.push_back(someone);
    }

    cin.clear();
    for (auto &p : people)
        cout << p.first << ' ' << p.second << endl;
}

int main()
{
    read_people_1();
    read_people_2();
    read_people_3();

    return 0;
}
