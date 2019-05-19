#include <iostream>
#include <fstream>
#include "StrBlob.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out input_file" << endl;
        return 0;
    }
    
    ifstream input(argv[1]);
    string line;
    StrBlob blob;

    while (getline(input, line))
        blob.push_back(line);

    for (StrBlobPtr beg(blob.begin()), end(blob.end()); beg != end; beg.incr())
    {
        cout << beg.deref() << '\n';
    }

    cout << endl;

    input.close();

    return 0;
}
