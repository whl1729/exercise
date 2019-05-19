#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out file_name" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    string word;
    string longest_word;
    const string ascender{"bdfhiklt"};
    const string descender{"gjpqy"};

    while (input >> word)
    {
        if ((word.find_first_of(ascender) == string::npos) &&
             word.find_first_of(descender) == string::npos &&
             word.size() > longest_word.size())
            longest_word = word;
    }

    input.close();

    cout << longest_word << endl;

    return 0;
}
