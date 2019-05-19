#ifndef __BULK_QUOTE_H__
#define __BULK_QUOTE_H__

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double disc):
        Disc_quote(book, p, qty, disc) { }
    double net_price(size_t n) const override;
};

#endif
