#include <iostream>
#include <string>
#include "Quote.h"
#include "15_15_Bulk_quote.h"

int main()
{
    Quote qt("BirdMan", 69);
    Bulk_quote bk("C++ Primer", 128, 3, 0.2);

    print_total(std::cout, qt, 5);
    print_total(std::cout, bk, 5);

    return 0;
}
