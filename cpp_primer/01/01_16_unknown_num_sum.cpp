#include <iostream>

int main()
{
    int sum = 0;
    int num;

    while (std::cin >> num)
    {
        sum += num;
    }

    std::cout << "Sum of input is " << sum << std::endl;

    return 0;
}
