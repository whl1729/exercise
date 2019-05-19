#include "Disc_quote.h"
#include "15_16_Limit_quote.h"

double Limit_quote::net_price(size_t qty) const
{
    return ((qty > quantity) ? price * (qty - quantity * discount) :
            price * qty * (1 - discount));
}
