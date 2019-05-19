#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>

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
    smatch sm;
    size_t pos;
    string fmt = "$2.$5.$7";
    ifstream in(argv[1]);

    while (getline(in, str))
    {
        sregex_iterator it(str.begin(), str.end(), r), end_it;
        sregex_iterator beg_it = it;
        if (it == end_it)
            continue;

        cout << it->prefix();

        if (++it == end_it)
            cout << beg_it->format(fmt) << endl;
        else
        {
            for (; it != end_it; ++it)
                cout << it->format(fmt) << " ";
            cout << endl;
        }
    }

    in.close();

    return 0;
}
