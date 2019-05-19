#include <iostream>
#include <fstream>
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

    read_file(string(argv[1]), vs);

    for (auto &line : vs)
        cout << line << endl;

    return 0;
}
