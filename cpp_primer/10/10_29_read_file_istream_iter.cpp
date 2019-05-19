#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out file_name" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    istream_iterator<string> in_iter(input), eof;
    vector<string> vs;

    copy(in_iter, eof, back_inserter(vs));

    ostream_iterator<string> out_iter(cout, " ");

    copy(vs.begin(), vs.end(), out_iter);

    cout << endl;

    input.close();

    return 0;
}
