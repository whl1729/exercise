#include <iostream>
#include "Sales_data.h"

using std::endl;

Sales_data& Sales_data::operator+=(const Sales_data &sd)
{
    units_sold += sd.units_sold;
    revenue += sd.revenue;
    return *this;
}

double Sales_data::avg_price() const
{
    return (units_sold ? (revenue / units_sold) : 0.0);
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data item = lhs;
    item += rhs;
    return item;
}

std::istream &operator>>(std::istream &input, Sales_data &sd)
{
    input >> sd.bookNo >> sd.units_sold >> sd.revenue;
    sd.revenue *= sd.units_sold;
    return input;
}

std::ostream &operator<<(std::ostream &output, const Sales_data &sd)
{
    output << sd.isbn() << ' ' << sd.units_sold << ' ' 
           << sd.revenue << ' ' << sd.avg_price() << endl;
    return output;
}
