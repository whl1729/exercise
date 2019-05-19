#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

void read(const string &file, vector<string> &text, 
          map<string, set<int>> &word_line, map<string, int> &word_count)
{
    ifstream input(file);
    string line, word;

    while (getline(input, line))
    {
        text.push_back(line);

        istringstream iss(line);
        while (iss >> word)
        {
            word_line[word].insert(text.size());
            ++word_count[word];
        }
    }

    input.close();
}

void query(const string &target, vector<string> &text,
           map<string, set<int>> &word_line, map<string, int> &word_count)
{
    if (word_count.find(target) == word_count.end())
    {
        cout << target << " occurs 0 time." << endl;
        return;
    }

    cout << target << " occurs " << word_count[target]
         << (word_count[target] > 1 ? " times" : " time") << endl;

    for (auto &l: word_line[target])
        cout << "    (line " << l << ") " << text[l-1] << endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out filename" << endl;
        return 1;
    }

    vector<string> text;
    map<string, set<int>> word_line;
    map<string, int> word_count;
    string word;

    read(argv[1], text, word_line, word_count);

    do
    {
        cout << "Enter a word to query or q to quit: " << endl;
        cin >> word;

        if (!cin || word == "q")
            break;

        query(word, text, word_line, word_count);
    } while (true);

    return 0;
}
