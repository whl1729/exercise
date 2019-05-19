#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int size = 20;
    int pos = 0;
    char *buf = new char[size]();
    char *tmp;
    char ch;
    
    cout << "Enter a string: " << endl;

    while (cin.get(ch))
    {
        buf[pos++] = ch;

        if (pos == size)
        {
            tmp = buf;
            buf = new char[size * 2]();
            strcpy(buf, tmp);
            free(tmp);
            size *= 2;
        }
    }

    for (int pos = 0; pos < strlen(buf); ++pos)
        cout << buf[pos];
    cout << endl;

    return 0;
}
