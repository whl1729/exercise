#include "Limit_quote.h"

void Limit_quote::debug() const
{
    Quote::debug();
    cout << "max_qty: " << max_qty << endl;
    cout << "discount: " << discount << endl;
}

double Limit_quote::net_price(size_t qty) const
{
    return ((qty > max_qty) ? price * (qty - max_qty * discount) :
            price * qty * (1 - discount));
}
