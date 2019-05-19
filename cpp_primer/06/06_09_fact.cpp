#include "Chapter6.h"

ullong fact(unsigned num)
{
    ullong fact = 1;

    for (; num > 1; num--)
        fact *= num;

    return fact;
}

