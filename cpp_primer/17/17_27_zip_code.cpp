#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string zip = "(\\d{5})(-)?(\\d{4})?";
    string fmt = "$1-$3";
    regex re(zip);
    string code;
    cout << "Enter some zip codes:" << endl;
    while (getline(cin, code))
    {
        for (sregex_iterator it(code.begin(), code.end(), re), end_it;
             it != end_it; ++it)
        {
            if ((*it)[2].matched && !(*it)[3].matched)
                cout << "not zip code" << endl;
            else if ((*it)[3].matched)
                cout << it->format(fmt) << endl;
            else
                cout << it->str() << endl;
        }
    }

    return 0;
}
