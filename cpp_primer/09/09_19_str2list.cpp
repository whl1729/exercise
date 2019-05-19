#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    list<string> slist;
    string word;

    cout << "Enter some words: " << endl;
    
    while (cin >> word)
        slist.push_back(word);

    for (auto s : slist)
        cout << s << endl;

    return 0;
}
