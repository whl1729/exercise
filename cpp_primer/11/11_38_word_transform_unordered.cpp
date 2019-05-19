#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

void set_rule(ifstream &input, unordered_map<string, string> &rules)
{
    string line;
    string::size_type pos;

    while (getline(input, line))
    {
        pos = line.find(' ');
        rules[line.substr(0, pos)] = line.substr(pos+1, line.size() - pos - 1);
    }
}

void word_transform(ifstream &input, unordered_map<string, string> &rules)
{
    string line, word;
    string::size_type start, end;

    while (getline(input, line))
    {
        start = 0;
        line += " ";
        while ((end = line.find(' ', start)) != string::npos)
        {
            word = line.substr(start, end - start);
            cout << ((rules.find(word) == rules.end()) ? word : rules[word]) << ' ';
            start = end + 1;
        }

        cout << endl;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Usage: ./a.out file1 file2" << endl;
        return 1;
    }

    ifstream in_rule(argv[1]);
    ifstream in_file(argv[2]);

    unordered_map<string, string> rules;

    set_rule(in_rule, rules);

    word_transform(in_file, rules);

    in_rule.close();
    in_file.close();

    return 0;
}
