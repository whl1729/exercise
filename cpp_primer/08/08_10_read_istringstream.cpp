#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void read_file(const string &file_name, vector<string> &vs)
{
    ifstream input(file_name);
    string line;

    while (getline(input, line))
        vs.push_back(line);

    input.close();
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: ./a.out file_name" << endl;
        return 1;
    }

    vector<string> vs;
    string word;

    read_file(string(argv[1]), vs);

    for (auto &line : vs)
    {
        istringstream iss(line);
        while (iss >> word)
            cout << word << endl;
    }

    return 0;
}
