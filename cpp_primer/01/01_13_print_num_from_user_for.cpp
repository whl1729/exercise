#include <iostream>

int main()
{
    int start = 0;
    int end = 0;
    
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> start >> end;

    for (int num = start; num <= end; num++)
    {
        std::cout << num << ' ';

        if (num % 10 == 0)
        {
            std::cout << '\n';
        }
    }

    std::cout << std::endl;

    return 0;
}
