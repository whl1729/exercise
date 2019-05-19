#include "Quote.h"

void Quote::debug() const
{
    cout << "-----------Debug Info for Quote------------" << endl;
    cout << "bookNo: " << bookNo << endl;
    cout << "price: " << price << endl;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
