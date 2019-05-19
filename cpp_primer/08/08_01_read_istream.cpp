#include <iostream>

using namespace std;

istream& read_istream(istream &is)
{
    string line;
    while (getline(is, line))
        cout << line << endl;

    is.clear(is.rdstate() & ~is.failbit & ~is.eofbit);
    //is.clear();

    return is;
}

int main()
{
    read_istream(cin);

    string greet;
    cin >> greet;
    cout << greet << endl;

    return 0;
}
