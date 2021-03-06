#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;
using namespace std::regex_constants;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out filename" << endl;
        return 0;
    }

    string phone = 
        "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone);
    string str;
    string fmt = "$2.$5.$7";
    ifstream in(argv[1]);

    while (getline(in, str))
        cout << regex_replace(str, r, fmt) << endl;
//        cout << regex_replace(str, r, fmt, format_no_copy) << endl;

    in.close();

    return 0;
}
