#include <iostream>
#include <string>

using namespace std;

void replace_str(string &s, string &oldVal, string &newVal)
{
    int pos = 0;
    int oldSize = oldVal.size();
    int newSize = newVal.size();

    while (pos <= s.size() - oldSize)
    {
        if (s.substr(pos, oldSize) == oldVal)
        {
            s.replace(pos, oldSize, newVal);
            pos += newSize;
        }
        else
        {
            ++pos;
        }
    }
}

int main()
{
    string s, oldVal, newVal;

    cout << "Enter a sentence: " << endl;
    getline(cin, s);

    cout << "Enter oldVal and newVal: " << endl;
    cin >> oldVal >> newVal;

    replace_str(s, oldVal, newVal);

    cout << s << endl;

    return 0;
}
