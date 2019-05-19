#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string exp;

    cout << "Enter regular expressions:" << endl;
    while (cin >> exp)
    {
        try 
        {
            regex r(exp, regex::icase);
        }
        catch (regex_error e)
        {
            cout << e.what() << "\ncode: " << e.code() << endl;
        }
    }

    return 0;
}
