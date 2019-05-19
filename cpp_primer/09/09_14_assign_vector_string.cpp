#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
    list<char *> fruits{"apple", "banana", "grade", "pear"};
    vector<string> vs(5, "water melon");
    vs.assign(fruits.cbegin(), fruits.cend());

    for (auto v : vs)
        cout << v << endl;

    return 0;
}
