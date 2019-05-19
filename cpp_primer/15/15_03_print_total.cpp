#include <iostream>
#include <string>
#include "Quote.h"

int main()
{
    Quote qt("BirdMan", 69);

    print_total(std::cout, qt, 5);

    return 0;
}
