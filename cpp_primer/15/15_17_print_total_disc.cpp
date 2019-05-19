#include <iostream>
#include <string>
#include "Disc_quote.h"

int main()
{
    Disc_quote qt("BirdMan", 69, 5, 0.2);

    print_total(std::cout, qt, 5);

    return 0;
}
