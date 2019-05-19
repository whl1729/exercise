#include <iostream>
#include <limits>

int main()
{
    int start = 0;
    int end = 0;
    int sum = 0;

    std::cout << "Enter two number: " << std::endl;
    std::cin >> start >> end;
    
    while (start <= end)
    {
        std::cout << start << ' ';
        start++;

        if (start % 10 == 0)
        {
            std::cout << '\n';
        }
    }

    std::cout << std::endl;

    return 0;
}
