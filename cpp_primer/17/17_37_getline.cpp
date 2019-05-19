#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out filename" << endl;
        return 1;
    }

    ifstream in(argv[1]);
    const int size = 80;
    char buf[size] = {0};

    while (in.getline(buf, 80, '\n'))
    {
        cout << buf << endl;
        memset(buf, 0, size);
    }

    return 0;
}
