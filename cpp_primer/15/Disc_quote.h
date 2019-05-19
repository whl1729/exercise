#ifndef __DISC_QUOTE_H__
#define __DISC_QUOTE_H__

#include "Quote.h"

class Disc_quote: public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double p, size_t qty, double disc):
        Quote(book, p), quantity(qty), discount(disc)  { }

    Disc_quote(const Disc_quote &dq):
        Quote(dq), quantity(dq.quantity), discount(dq.discount)  { }

    Disc_quote(Disc_quote &&dq):
        Quote(std::move(dq)), quantity(dq.quantity), discount(dq.discount)  { }

    Disc_quote& operator=(const Disc_quote &dq)
    {
        Quote::operator=(dq);
        quantity = dq.quantity;
        discount = dq.discount;
    }

    Disc_quote& operator=(Disc_quote &&dq)
    {
        Quote::operator=(std::move(dq));
        quantity = dq.quantity;
        discount = dq.discount;
    }

    ~Disc_quote() { }

    double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

#endif
