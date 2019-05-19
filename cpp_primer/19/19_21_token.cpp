#include <iostream>
#include "Token.h"

using namespace std;

int main()
{
    Token tk;
    tk.print();

    tk = 1729;
    tk.print();

    tk = 'w';
    tk.print();

    tk = 3.14;
    tk.print();

    tk = "hello world";
    tk.print();

    return 0;
}
