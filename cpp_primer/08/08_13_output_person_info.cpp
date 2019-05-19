#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const string &phone)
{
    for (auto c : phone)
        if (!isdigit(c))
            return false;

    return true;
}

string format(const string &phone)
{
    return (string("86-") + phone);
}

void read_person_info(vector<PersonInfo> &people, istream &is)
{
    string line, word;
    istringstream record;

    while (getline(is, line))
    {
        PersonInfo info;
        record = istringstream(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
}

void write_person_info(vector<PersonInfo> &people, ostream &os)
{
    for (const auto &entry : people)
    {
        ostringstream formmatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
                badNums << " " << nums;
            else
                formmatted << " " << format(nums);
        }

        if (badNums.str().empty())
            os << entry.name << " " << formmatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s)" << badNums.str() << endl;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out file-name" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    vector<PersonInfo> vp;

    read_person_info(vp, input);
    write_person_info(vp, cout);

    return 0;
}
