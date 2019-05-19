#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReadLine
{
public:
    ReadLine(istream &in = cin): input(in) { }
    string operator()() 
    {
        getline(input, line);
        return input ? line : string();
    }
private:
    istream &input;
    string line;
};

int main()
{
    ReadLine readline;
    vector<string> text;
    string nulstr, line;

    while ((line = readline()) != nulstr)
        text.push_back(line);

    for (auto &t : text)
        cout << t << endl;

    return 0;
}
