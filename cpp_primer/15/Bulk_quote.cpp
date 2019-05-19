#include "Quote.h"
#include "Bulk_quote.h"

void Bulk_quote::debug() const
{
    Quote::debug();
    cout << "min_qty: " << min_qty << endl;
    cout << "discount: " << discount << endl;
}

double Bulk_quote::net_price(size_t cnt) const 
{
    return (cnt >= min_qty)? (cnt * (1 - discount) * price) : (cnt * price);
}
