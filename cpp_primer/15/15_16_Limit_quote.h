#ifndef __LIMIT_H__
#define __LIMIT_H__

#include "Quote.h"

class Limit_quote: public Disc_quote
{
public:
    Limit_quote() = default;
    Limit_quote(const string &book, double p, size_t qty, double disc):
        Disc_quote(book, p, qty, disc) { }
    double net_price(size_t qty) const override;
};

#endif
