#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phone;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    while (getline(cin, line))
    {
        PersonInfo info;
        record = istringstream(line);
        record >> info.name;
        while (record >> word)
            info.phone.push_back(word);
        people.push_back(info);
    }

    for (auto info : people)
    {
        cout << info.name << "'s phone: " << endl;
        for (auto ph : info.phone)
            cout << ph << endl;
    }

    return 0;
}
