#include <iostream>

using namespace std;

int main()
{
    string word, prev;

    while (cin >> word)
    {
        if (word == prev)
        {
            cout << word << " occurs twice" << endl;
            break;
        }

        prev = word;
    }

    if (word != prev)
        cout << "no word was repeated" << endl;

    return 0;
}
