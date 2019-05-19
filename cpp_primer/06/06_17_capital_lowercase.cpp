#include <iostream>

using namespace std;

bool has_capital(const string &str);
void to_lower(string &str);

int main()
{
    string str;

    cout << "Enter words: " << endl;

    while (cin >> str)
    {
        if (has_capital(str))
        {
            cout << str << " has capital letters, its lowercase: ";
            to_lower(str);
            cout << str << endl;
        }
        else
        {
            cout << str << " hasn't capital letters." << endl;
        }
    }

    return 0;
}

bool has_capital(const string &str)
{
    for (auto c: str)
    {
        if (isupper(c))
            return true;
    }

    return false;
}

void to_lower(string &str)
{
    for (auto &c : str)
    {
        c = tolower(c);
    }
}
