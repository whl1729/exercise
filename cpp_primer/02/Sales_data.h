#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

struct Sales_data
{
    std::string isbn;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

void copy_sales_data(const Sales_data &src, Sales_data &dest);
void print_sales_data(const Sales_data &data);

#endif
