#include <iostream>

using namespace std;

void print_io_state()
{
    cout << "rdstate=" << cin.rdstate() << endl;
    cout << "badbit=" << istream::badbit << endl;
    cout << "failbit=" << istream::failbit << endl;
    cout << "eofbit=" << istream::eofbit << endl;
    cout << "goodbit=" << istream::goodbit << endl;
}

int main()
{
    int num;
    
    cout << "Enter a number: " << endl;
    while (cin >> num)
        print_io_state();

    print_io_state();

    return 0;
}
