#include <iostream>

using namespace std;

int main()
{
    string word, prev;

    while (cin >> word)
    {
        if (!isupper(word[0]) || word != prev)
        {
            prev = word;
            continue;
        }

        cout << word << " occurs twice" << endl;
    }

    if (word != prev)
        cout << "no word was repeated" << endl;

    return 0;
}
