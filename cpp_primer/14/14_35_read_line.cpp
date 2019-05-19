#include <iostream>
#include <string>

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
    cout << readline() << endl;
    return 0;
}
