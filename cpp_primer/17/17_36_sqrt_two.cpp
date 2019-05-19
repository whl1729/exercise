#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    cout << left
         << setw(20) << "default format: " << 100 * sqrt(2.0) << "\n"
         << setw(20) << "scientific: " << scientific << 100 * sqrt(2.0) << "\n"
         << setw(20) << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << uppercase
         << setw(20) << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << "\n"
         << nouppercase
         << setw(20) << "use default: " << defaultfloat << 100 * sqrt(2.0) << "\n\n"
         << right;

    return 0;
}
