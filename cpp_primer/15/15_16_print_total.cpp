#include <iostream>
#include <string>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"

int main()
{
    Quote qt("BirdMan", 69);
    Bulk_quote bk("C++ Primer", 128, 3, 0.2);
    Limit_quote lm("Harry Potter", 100, 7, 0.3);

    print_total(std::cout, qt, 5);
    print_total(std::cout, bk, 5);
    print_total(std::cout, lm, 6);
    print_total(std::cout, lm, 10);

    return 0;
}
