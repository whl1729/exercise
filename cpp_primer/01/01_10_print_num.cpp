#include <iostream>

int main()
{
    int num = 10;

    while (num >= 0)
    {
        std::cout << num-- << ' ';
    }

    std::cout << '\n';
    //std::cout << std::endl;

    return 0;
}
