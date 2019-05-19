#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> text;
    string line;

    while (getline(cin, line))
        text.push_back(line);

    for (auto it = text.begin(); 
        it != text.end() && !it->empty(); it++)
    {
        for (auto cit = it->begin(); cit != it->end(); cit++)
            *cit = toupper(*cit);

        cout << *it << ' ';
    }

    cout << endl;

    return 0;
}
