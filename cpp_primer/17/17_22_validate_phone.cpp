#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool valid(const smatch &m);

int main()
{
    string phone =
        "(\\()?(\\d{3})(\\))?([-.])?([ ]+)?(\\d{3})([ ]+)?([-.])?(\\d{4})";
    //     1       2    3       4     5       6      7       8       9
    regex r(phone);
    smatch m;
    string s;

    cout << "Enter some phone numbers: " << endl;
    while (getline(cin, s))
    {
        for (sregex_iterator it(s.begin(), s.end(), r), end_it;
             it != end_it; ++it)
            if (valid(*it))
                cout << "valid: " << it->str() << endl;
            else
                cout << "not valid: " << it->str() << endl;
    }
    return 0;
}

// check parenthesis matches
// check the separate
bool valid(const smatch &m)
{
    if (m[1].matched)
        return m[3].matched &&
               !m[4].matched && !m[8].matched;
    else
        return !m[3].matched && m[4].str() == m[8].str() &&
                (!m[4].matched || 
                 (m[4].matched && !m[5].matched && !m[7].matched));
}
