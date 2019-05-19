#include <iostream>
#include <string>

using namespace std;

void replace_str(string &s, const string &oldVal, const string &newVal)
{
    int oldSize = oldVal.size();
    int newSize = newVal.size();

    for (auto cur = s.begin(); cur <= s.end() - oldSize; )
    {
        if (string(cur, cur + oldSize) == oldVal)
        {
            s.erase(cur, cur + oldSize);
            cur = s.insert(cur, newVal.begin(), newVal.end());
            cur += newSize;
        }
        else
        {
            ++cur;
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
