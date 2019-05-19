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
    Quote() { cout << "Quote()" << endl; };
    Quote(const string &book, double sales_price):
         bookNo(book), price(sales_price) 
    { cout << "Quote(const string&, double)" << endl; }

    Quote(const Quote &q):
        bookNo(q.bookNo), price(q.price)
    { cout << "Quote(const Quote &q)" << endl; }

    Quote(Quote &&q):
        bookNo(q.bookNo), price(q.price)
    { cout << "Quote(Quote &&q)" << endl; }

    Quote& operator=(const Quote &q)
    {
        bookNo = q.bookNo;
        price = q.price;
        cout << "operator=(const Quote &q)" << endl;
    }

    Quote& operator=(Quote &&q)
    {
        bookNo = q.bookNo;
        price = q.price;
        cout << "operator=(Quote &q)" << endl;
    }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const
    { return n * price; }
    virtual ~Quote() { cout << "~Quote()" << endl; }
    virtual void debug() const;
private:
    string bookNo;
protected:
    double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n);

#endif
