#include <iostream>

using std::cout;
using std::endl;

namespace primerLib
{
    void compute() { cout << "compute()" << endl; }
    void compute(const void *) { cout << "compute(const void *)" << endl; }
}

using primerLib::compute;
void compute(int) { cout << "compute(int)" << endl; }
void compute(double, double = 3.4) { cout << "compute(double, double = 3.4)" << endl; }
void compute(char*, char* = 0) { cout << "compute(char*, char* = 0)" << endl; }

void f()
{
    compute(0);
}

int main()
{
    f();
    return 0;
}
