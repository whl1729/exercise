#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>

struct Sales_data
{
friend std::istream &read(std::istream&, Sales_data&);
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:
    Sales_data(const std::string &s, unsigned n, double p) :
               bookNo(s), units_sold(n), revenue(p*n) 
    { 
        std::cout << "Initialized with 3 arguments." << std::endl; 
    }

    Sales_data(): Sales_data("", 0, 0) 
    { 
        std::cout << "Initialized with no arguments." << std::endl; 
    }

    Sales_data(const std::string &s) : Sales_data(s, 0, 0)
    { 
        std::cout << "Initialized with a string argument." << std::endl;  
    }
    
    Sales_data(std::istream &is) : Sales_data()
    { 
        std::cout << "Initialized with an istream argument." << std::endl;
        read(is, *this); 
    }

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


std::istream &read(std::istream&, Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);

#endif
