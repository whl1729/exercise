#include <iostream>
#include <string>
#include "13_42_TextQuery.h"

using namespace std;

void runQueries(string file)
{
    vector<string> text;
    map<string, set<int>> word_line;
    map<string, int> word_count;
    string word;

    TextQuery tq(file);

    while (true)
    {
        cout << "Enter a word to query or q to quit: " << endl;
        cin >> word;

        if (!cin || word == "q")
            break;

        print(cout, tq.query(word));
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out filename" << endl;
        return 1;
    }

    runQueries(argv[1]);

    return 0;
}
