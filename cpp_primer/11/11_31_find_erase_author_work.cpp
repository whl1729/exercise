#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

void print(const multimap<string, string> &authors)
{
    for (auto &au : authors)
        cout << au.first << " " << au.second <<endl;
}

int main()
{
    multimap<string, string> authors;
    string person, book;

    cout << "Enter author's name and his work: " << endl;

    while (cin >> person >> book)
    {
        authors.emplace(person, book);
    }

    print(authors);

    cin.clear();

    cout << "Enter a author's name to erase his work: " << endl;
    cin >> person;

    auto iter = authors.find(person);
    if (iter != authors.end())
        authors.erase(iter);

    print(authors);

    return 0;
}
