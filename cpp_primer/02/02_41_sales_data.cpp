#include <iostream>

struct Sales_data
{
    std::string isbn;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

void add_two_items();
void add_multi_items();
void count_items();

int main()
{
    add_two_items();

    //add_multi_items();

    count_items();

    return 0;
}

void add_two_items()
{
    Sales_data data1, data2, sum;
    double price;

    std::cout << "Enter the isbn, units_sold and price of the transaction: " << std::endl;
    std::cin >> data1.isbn >> data1.units_sold >> price;
    data1.revenue = price * data1.units_sold;

    std::cout << "Enter the isbn, units_sold and price of the transaction: " << std::endl;
    std::cin >> data2.isbn >> data2.units_sold >> price;
    data2.revenue = price * data2.units_sold;

    if (data1.isbn == data2.isbn)
    {
        sum.isbn = data1.isbn;
        sum.units_sold = data1.units_sold + data2.units_sold;
        sum.revenue = data1.revenue + data2.revenue;
        price = sum.revenue / sum.units_sold;

        std::cout << sum.isbn << ' ' << sum.units_sold << ' ';
        std::cout << sum.revenue << ' ' << price << std::endl;
    }
    else
    {
        std::cout << "Data must refer to the same ISBN" << std::endl;
    }
}

void add_multi_items()
{
    Sales_data last, cur;
    double price, avg_price;

    if (std::cin >> last.isbn >> last.units_sold >> price)
    {
        last.revenue = price * last.units_sold;

        while (std::cin >> cur.isbn >> cur.units_sold >> price)
        {
            if (cur.isbn == last.isbn)
            {
                last.units_sold += cur.units_sold;
                last.revenue += price * cur.units_sold;
            }
            else
            {
                avg_price = last.revenue / last.units_sold;
                std::cout << last.isbn << ' ' << last.units_sold << ' '
                          << last.revenue << ' ' << avg_price << std::endl;

                last.isbn = cur.isbn;
                last.units_sold = cur.units_sold;
                last.revenue = price * cur.units_sold;
            }
        }
                
        std::cout << last.isbn << last.units_sold << last.revenue 
                  << avg_price << std::endl;
    }
    else
    {
        std::cout << "No data" << std::endl;
    }
}

void count_items()
{
    Sales_data last, cur;
    double price;
    int count = 1;

    if (std::cin >> last.isbn >> last.units_sold >> price)
    {
        while (std::cin >> cur.isbn >> cur.units_sold >> price)
        {
            if (cur.isbn == last.isbn)
            {
                count++;
            }
            else
            {
                std::cout << last.isbn << ": " << count << std::endl;

                last.isbn = cur.isbn;
                count = 1;
            }
        }
    }
    else
    {
        std::cout << "No data" << std::endl;
    }
}
