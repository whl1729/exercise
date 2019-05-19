#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    deque<string> sdeq;
    string word;

    cout << "Enter some words: " << endl;
    
    while (cin >> word)
        sdeq.push_back(word);

    for (auto s : sdeq)
        cout << s << endl;

    return 0;
}
