#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    cout << "default format: " << 100 * sqrt(2.0) << "\n"
         << "scientific: " << scientific << 100 * sqrt(2.0) << "\n"
         << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << uppercase
         << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << "\n"
         << nouppercase
         << "use default: " << defaultfloat << 100 * sqrt(2.0) << "\n\n";

    return 0;
}
