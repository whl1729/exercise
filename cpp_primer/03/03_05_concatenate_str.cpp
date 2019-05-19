#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string cur;
    string total;

    while (cin >> cur)
        total += cur + " ";

    cout << total << endl;

    return 0;
}
