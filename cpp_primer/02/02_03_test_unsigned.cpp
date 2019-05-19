#include <iostream>

int main()
{
    unsigned u = 10;
    unsigned u2 = 42;
    int v = -42;
    int i = 10;
    int i2 = 42;

    std::cout << "v + v = " << v + v << std::endl;
    std::cout << "u + v = " << u + v << std::endl;
    std::cout << "u * v = " << u * v << std::endl;

    std::cout << "u2 - u = " << u2 -u << std::endl;
    std::cout << "u - u2 = " << u - u2 << std::endl;

    std::cout << "i2 - i = " << i2 - i << std::endl;
    std::cout << "i - i2 = " << i - i2 << std::endl;
    std::cout << "i - u = " << i - u << std::endl;
    std::cout << "u - i = " << u - i << std::endl;

    return 0;
}
