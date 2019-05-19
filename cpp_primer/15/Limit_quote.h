#ifndef __LIMIT_H__
#define __LIMIT_H__

#include "Quote.h"

class Limit_quote: public Quote
{
public:
    Limit_quote() = default;
    Limit_quote(const string &book, double p, size_t qty, double disc):
        Quote(book, p), max_qty(qty), discount(disc)  { }
    double net_price(size_t qty) const override;
    void debug() const override;
private:
    size_t max_qty = 0;
    double discount = 0.0;
};

#endif
