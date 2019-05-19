#include <iostream>

using namespace std;

void set_bc(const char *pattern, int len, int *bc);

const int len = 27;

int main()
{
    string pattern;
    int bc[len];

    cout << "Enter pattern: " << endl;
    getline(cin, pattern);

    set_bc(pattern.c_str(), pattern.size(), bc);

    for (auto b : bc)
        cout << b << ' ';
    cout << endl;

    return 0;
}


void set_bc(const char *pattern, int size, int *bc)
{
    int pos;
    for (pos = 0; pos < len; pos++)
        bc[pos] = -1;

    for (pos = 0; pos < size; pos++)
    {
        if (pattern[pos] == ' ')
            bc[len - 1] = pos;
        else
            bc[pattern[pos] - 'a'] = pos;
    }
}
