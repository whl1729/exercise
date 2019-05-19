#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i = -16;
    double d = 3.14159;

    cout << "i: " << setw(12) << i << "next col\n"
         << "d: " << setw(12) << d << "next col\n";

    cout << left
         << "i: " << setw(12) << i << "next col\n"
         << "d: " << setw(12) << d << "next col\n"
         << right;

    cout << right
         << "i: " << setw(12) << i << "next col\n"
         << "d: " << setw(12) << d << "next col\n";

    cout << internal
         << "i: " << setw(12) << i << "next col\n"
         << "d: " << setw(12) << d << "next col\n";

    cout << setfill('#')
         << "i: " << setw(12) << i << "next col\n"
         << "d: " << setw(12) << d << "next col\n"
         << setfill(' ');

    return 0;
}
