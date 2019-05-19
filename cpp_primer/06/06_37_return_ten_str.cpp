#include <iostream>

using namespace std;

string g_str[10];


using str_arr = string[10];

str_arr &ten_str_1(const string &str);
auto ten_str_2(const string &str) -> string(&)[10];
decltype(g_str) &ten_str_3(const string &str);

int main()
{
    string word;

    cout << "Enter a word: " << endl;
    cin >> word;

    str_arr &strs_1 = ten_str_1(word);

    for (auto s : strs_1)
        cout << s << ' ';

    cout << endl;

    string (&strs_2)[10] = ten_str_2(word);

    for (auto s : strs_2)
        cout << s << ' ';

    cout << endl;

    decltype(g_str) &strs_3 = ten_str_1(word);

    for (auto s : strs_3)
        cout << s << ' ';

    cout << endl;

    return 0;
}

str_arr &ten_str_1(const string &str)
{
    for (auto &s : g_str)
        s = str;

    return g_str;
}

auto ten_str_2(const string &str) -> string(&)[10]
{
    for (auto &s : g_str)
        s = str;

    return g_str;
}

decltype(g_str) &ten_str_3(const string &str)
{
    for (auto &s : g_str)
        s = str;

    return g_str;
}
