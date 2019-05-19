#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <regex>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const smatch &m)
{
    if (m[1].matched)
        return m[3].matched &&
               (m[4].matched == 0 || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}

string phone =
    "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
regex r(phone);

bool valid(const string &phone)
{
    smatch sm;

    return regex_match(phone, sm, r) && valid(sm);
}

string format(const string &phone)
{
//    return (string("86-") + phone);
    return phone;
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
