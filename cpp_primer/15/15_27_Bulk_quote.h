#ifndef __BULK_QUOTE_H__
#define __BULK_QUOTE_H__

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
    using Disc_quote::Disc_quote;
    Bulk_quote() { cout << "Bulk_quote()" << endl; }
    Bulk_quote(const Bulk_quote &bq):
        Disc_quote(bq)
    { cout << "Bulk_quote(const Bulk_quote &bq)" << endl; }

    Bulk_quote(Bulk_quote &&bq):
        Disc_quote(std::move(bq))
    { cout << "Bulk_quote(Bulk_quote &&bq)" << endl; }

    Bulk_quote& operator=(const Bulk_quote &bq)
    {
        Disc_quote::operator=(bq);
        cout << "operator=(const Bulk_quote &bq)" << endl;
    }

    Bulk_quote& operator=(Bulk_quote &&bq)
    {
        Disc_quote::operator=(std::move(bq));
        cout << "operator=(Bulk_quote &&bq)" << endl;
    }

    ~Bulk_quote()
    { cout << "~Bulk_quote()" << endl; }

    double net_price(size_t n) const override;
};

#endif
