#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item;
    std::string isbn;
    int count = 1;

    if (std::cin >> item)
    {
        isbn = item.isbn();

        while (std::cin >> item)
        {
            if (item.isbn() == isbn)
            {
                count++;
            }
            else
            {
                std::cout << isbn << " : " << count << std::endl;
                isbn = item.isbn();
                count = 1;
            }
        }
                
        std::cout << isbn << " : " << count << std::endl;
    }
    else
    {
        std::cout << "Invalid input." << std::endl;
    }

    return 0;
}
