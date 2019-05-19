#ifndef __BASKET_H__
#define __BASKET_H__

#include <set>
#include <memory>
#include <iostream>
#include "Quote.h"

using std::shared_ptr;
using std::multiset;
using std::ostream;

class Basket
{
public:
    void add_item(const shared_ptr<Quote> &sale)
    { items.insert(sale); }

    void add_item(const Quote &sale)
    { items.insert(shared_ptr<Quote>(sale.clone())); }

    void add_item(Quote &&sale)
    { items.insert(shared_ptr<Quote>(std::move(sale).clone())); }

    double total_receipt(ostream&) const;
private:
    static bool compare(const shared_ptr<Quote> &lhs,
                        const shared_ptr<Quote> &rhs)
    { return lhs->isbn() < rhs->isbn(); }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif
