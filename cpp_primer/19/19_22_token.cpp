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

    tk = Sales_data("Walden", 5, 35.0);
    tk.print();

    return 0;
}
