#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Equal
{
public:
    Equal(const string &s = "", const int &i = 0): ival(i), sval(s) { }
    bool operator()(const int &rhs) const { return rhs == ival; }
    bool operator()(const string &rhs) const { return rhs == sval; }
private:
    int ival;
    string sval;
};

void print_svec(vector<string> vs)
{
    for (auto &s : vs)
        cout << s << " ";
    cout << endl;
}

int main()
{
    vector<string> vs{"I", "don't", "care", "who", "you", "are", "where", "you", "from", "what", "you", "do"};
    Equal equal("you");

    print_svec(vs);
    replace_if(vs.begin(), vs.end(), equal, "they");
    print_svec(vs);

    return 0;
}
