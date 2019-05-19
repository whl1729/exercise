#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
    smatch results;
    string filename;
    while (cin >> filename)
        if (regex_search(filename, results, r))
            cout << results.str()  << " "
                 << results.str(0) << " " 
                 << results.str(1) << " " 
                 << results.str(2) << endl;

    return 0;
}
