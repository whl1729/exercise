#ifndef __QUOTE_H__
#define __QUOTE_H__

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::size_t;
using std::ostream;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
         bookNo(book), price(sales_price) { }
    Quote(const Quote &q):
        bookNo(q.bookNo), price(q.price) { }
    Quote(Quote &&q):
        bookNo(q.bookNo), price(q.price) { }

    Quote& operator=(const Quote &q)
    {
        bookNo = q.bookNo;
        price = q.price;
    }

    Quote& operator=(Quote &&q)
    {
        bookNo = q.bookNo;
        price = q.price;
    }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const
    { return n * price; }
    virtual ~Quote() = default;
    virtual void debug() const;
    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(std::move(*this)); }
private:
    string bookNo;
protected:
    double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n);

#endif
