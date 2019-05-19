#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

struct Sales_data
{
friend std::istream &operator>>(std::istream &input, Sales_data &sd);
friend std::ostream &operator<<(std::ostream &output, const Sales_data &sd);
friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

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

#endif
