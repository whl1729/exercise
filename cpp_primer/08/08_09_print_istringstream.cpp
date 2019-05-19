#include <iostream>
#include <sstream>

using namespace std;

istream& read_istream(istream &is)
{
    string line;
    while (getline(is, line))
        cout << line << endl;

    //is.clear(is.rdstate() & ~is.failbit & ~is.eofbit);
    is.clear();

    return is;
}

int main()
{
    istringstream iss("Hello World\nLife is short, I use Python\nSeize the day");

    read_istream(iss);

    string greet;
    cin >> greet;
    cout << greet << endl;

    return 0;
}
