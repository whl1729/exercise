#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CheckLen
{
public:
    CheckLen(int low = 1, int high = 10): min(low), max(high) { }
    bool operator()(const string &word) 
        { return word.size() >= min && word.size() <= max; }
private:
    int min;
    int max;
};

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out filename" << endl;
        return 1;
    }

    vector<string> text;
    string word;
    ifstream input(argv[1]);

    while (input >> word)
        text.push_back(word);

    cout << count_if(text.begin(), text.end(), CheckLen()) << endl;

    return 0;
}
