#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<char> vc{'h', 'e', 'l', 'l', 'o', 0};

    string str(vc.cbegin(), vc.cend());

    cout << str << endl;

    return 0;
}
