#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item cur;
    Sales_item sum;

    if (std::cin >> sum)
    {
        while (std::cin >> cur)
        {
            sum += cur;
        }

        std::cout << sum << std::endl;
    }
    else
    {
        std::cout << "No Input or Invalid input." << std::endl;
    }

    return 0;
}
