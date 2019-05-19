#include <iostream>
#include <string>
#include "MyTextQuery.h"
#include "MyQueryResult.h"

using namespace std;

void runQueries(string file)
{
    vector<string> text;
    map<string, set<int>> word_line;
    map<string, int> word_count;
    string cmd;

    TextQuery tq(file);

    while (true)
    {
        cout << "Enter a command to query or q to quit: " << endl;
        getline(cin, cmd);

        if (!cin || cmd == "q")
            break;

        print(cout, tq.query(cmd));
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
