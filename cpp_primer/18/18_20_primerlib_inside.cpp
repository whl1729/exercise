#include <iostream>

using std::cout;
using std::endl;

namespace primerLib
{
    void compute() { cout << "compute()" << endl; }
    void compute(const void *) { cout << "compute(const void *)" << endl; }
}

void compute(int) { cout << "compute(int)" << endl; }
void compute(double, double = 3.4) { cout << "compute(double, double = 3.4)" << endl; }
void compute(char*, char* = 0) { cout << "compute(char*, char* = 0)" << endl; }

void f()
{
    using primerLib::compute;
    compute(0);
}

int main()
{
    f();
    return 0;
}
