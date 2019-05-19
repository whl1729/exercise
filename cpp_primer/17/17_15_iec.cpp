#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    string test_str;

    cout << "Enter some words:" << endl;
    while (cin >> test_str)
    {
        if (regex_search(test_str, r))
            cout << "error! it violate the \"i before e except after c\" rule" << endl;
        else
            cout << "ok" << endl;
    }

    return 0;
}
