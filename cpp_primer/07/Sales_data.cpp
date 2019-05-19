#include <iostream>
#include "Sales_data.h"

using namespace std;

Sales_data& Sales_data::combine(const Sales_data& data)
{
    units_sold += data.units_sold;
    revenue += data.revenue;

    return *this;
}

double Sales_data::avg_price() const
{
    return (units_sold ? (revenue / units_sold) : 0.0);
}

Sales_data add(const Sales_data& first, const Sales_data& second)
{
    Sales_data sum = first;
    sum.combine(second);
    return sum;
}

std::ostream &print(std::ostream& os, const Sales_data& data)
{
    os << data.isbn() << ' ' << data.units_sold << ' ' 
       << data.revenue << ' ' << data.avg_price() << endl;

    return os;
}

std::istream &read(std::istream& is, Sales_data& data)
{
    is >> data.bookNo >> data.units_sold >> data.revenue;
    data.revenue *= data.units_sold;

    return is;
}
