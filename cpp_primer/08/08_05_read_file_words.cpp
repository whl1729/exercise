#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void read_file(const string &file_name, vector<string> &vs)
{
    ifstream input(file_name);
    string word;

    while (input >> word)
        vs.push_back(word);

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

    for (auto &word : vs)
        cout << word << endl;

    return 0;
}
