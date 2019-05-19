#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    string file("receive freind receipt theif height freight");
    regex r(pattern, regex::icase);

    for (sregex_iterator it(file.begin(), file.end(), r), end_it;
         it != end_it; ++it)
    {
        auto pos = it->prefix().length();
        pos = pos > 40 ? pos - 40 : 0;
        cout << it->prefix().str().substr(pos)
             << "\n\t\t>>> " << it->str() << " <<<\n"
             << it->suffix().str().substr(0, 40) << endl;
    }

    return 0;
}
