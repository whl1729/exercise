#include <iostream>

using namespace std;

int serial_num()
{
    static int cnt = 1;
    return cnt++;
}

class numbered
{
public:
    numbered() { mysn = serial_num(); }
    numbered(const numbered& s) { mysn = serial_num(); }
    numbered& operator=(const numbered& s) { mysn = serial_num(); }
    int mysn;
};

void print_mysn(const numbered& s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;

    print_mysn(a);
    print_mysn(b);
    print_mysn(c);

    b = a;
    a = c;

    print_mysn(a);
    print_mysn(b);
    print_mysn(c);

    return 0;
}
