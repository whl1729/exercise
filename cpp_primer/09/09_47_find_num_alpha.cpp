#include <iostream>
#include <string>

using namespace std;

void find_first_of(const string &str, const string &pattern)
{
    for (string::size_type pos = 0; (pos = str.find_first_of(pattern, pos)) != string::npos; ++pos)
    {
        cout << str[pos] << ' ';
    }

    cout << endl;
}

void find_first_not_of(const string &str, const string &pattern)
{
    for (string::size_type pos = 0; (pos = str.find_first_not_of(pattern, pos)) != string::npos; ++pos)
    {
        cout << str[pos] << ' ';
    }

    cout << endl;
}

int main()
{
    const string str{"ab2c3d7R4E6"};
    const string nums{"0123456789"};
    const string alph{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};


    find_first_of(str, nums);
    find_first_of(str, alph);
    find_first_not_of(str, alph);
    find_first_not_of(str, nums);

    return 0;
}
