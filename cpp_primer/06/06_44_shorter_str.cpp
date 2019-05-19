#include <iostream>

using namespace std;

inline bool isShorter(const string &str1, const string &str2)
{
    return (str1.size() < str2.size());
}

int main()
{
    string str1, str2;

    cout << "Enter two words: " << endl;
    cin >> str1 >> str2;
    cout << str1 << " is" << (isShorter(str1, str2) ? "" : " not") 
         << " shorter than " << str2 << endl;

    return 0;
}
