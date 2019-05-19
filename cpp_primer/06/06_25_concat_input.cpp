#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    string input;

    for (int pos = 0; pos < argc; ++pos)
        input += string(argv[pos]) + ' ';

    cout << input << endl;

    return 0;
}
