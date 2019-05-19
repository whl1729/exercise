#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i = -10;
    double d = 314.15926;
    cout << boolalpha << (1 < 2) << " " << (1>2) << noboolalpha << endl;
    cout << showbase << i << " " << 077 << " " << 0xff << endl;
    cout << showpoint << (float)100000 << " " << (float)100000000 << " " << (float)100 << " " << (float)1000 << endl;
    cout << showpos << i << noshowpos << endl;
    cout << hex << i << " " << uppercase << i << endl;
    cout << scientific << d << " " << d << nouppercase << defaultfloat << endl;
    cout << (1 < 2) << " " << (1 > 2) << endl;

    cout << "defalut: " << 20 << " " << 1024 << endl;
    cout << "octal: " << oct << 20 << " " << 1024 << endl;
    cout << "hex: " << hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << dec << 20 << " " << 1024 << endl;

    cout << "Precision: " << cout.precision()
         << ", Value: " << sqrt(2.0) << endl;
    
    int pre = cout.precision();

    cout.precision(12);
    cout << "Precision: " << cout.precision()
         << ", Value: " << sqrt(2.0) << endl;

    cout << setprecision(3);
    cout << "Precision: " << cout.precision()
         << ", Value: " << sqrt(2.0) << endl;

    cout.precision(pre);
    cout << "default format: " << 100 * sqrt(2.0) << "\n"
         << "scientific: " << scientific << 100 * sqrt(2.0) << "\n"
         << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << "\n"
         << "use default: " << defaultfloat << 100 * sqrt(2.0) << "\n\n";

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

    char ch;
    cin >> noskipws;
    while (cin >> ch)
        cout << ch;
    cin >> skipws;

    return 0;
}
