#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <stdexcept>

struct Sales_data
{
friend std::istream &operator>>(std::istream &input, Sales_data &sd);
friend std::ostream &operator<<(std::ostream &output, const Sales_data &sd);
friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
friend struct std::hash<Sales_data>;

public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p) :
               bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &is) { is >> *this; }
    Sales_data& operator+=(const Sales_data &sd);
    Sales_data& operator=(const std::string &s);
    operator std::string() const { return bookNo; }
    operator double() const { return revenue; }

    std::string isbn() const { return bookNo; }

private:
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &operator>>(std::istream &input, Sales_data &sd);
std::ostream &operator<<(std::ostream &output, const Sales_data &sd);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);

namespace std
{
    template <>
    struct hash<Sales_data>
    {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data &s) const;
    };
}

class out_of_stock: public std::runtime_error
{
public:
    explicit out_of_stock(const std::string &s):
        std::runtime_error(s) { }
};

class isbn_mismatch: public std::logic_error
{
public:
    explicit isbn_mismatch(const std::string &s):
        std::logic_error(s) { }
    isbn_mismatch(const std::string &s, const std::string &lhs,
                  const std::string &rhs):
        std::logic_error(s), left(lhs), right(rhs) { }
    const std::string left, right;
};

#endif
