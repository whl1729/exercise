#include <iostream>

using namespace std;

string g_str[10];

string (&ten_str(const string &str))[10];

int main()
{
    string word;

    cout << "Enter a word: " << endl;
    cin >> word;

    string (&strs)[10] = ten_str(word);

    for (auto s : strs)
        cout << s << ' ';

    cout << endl;

    return 0;
}

string (&ten_str(const string &str))[10]
{
    for (auto &s : g_str)
        s = str;

    return g_str;
}
