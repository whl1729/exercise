#include <iostream>
#include <vector>
#include "13_50_String.h"

using namespace std;

int main()
{
    vector<String> vs;
    String word = "hello world";
    vs.push_back(word);
    vs.push_back("done");

    cout << "Enter some words:" << endl;

    while (cin >> word)
        vs.push_back(word);

    for (auto &s : vs)
        cout << s << endl;

    return 0;
}
