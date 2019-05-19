#include <iostream>

// The program solve exercise 1.4 and 1.5: print the product of two numbers, 
// and you are required to use a separate statement to print each operand.
int main()
{
    int v1 = 0;
    int v2 = 0;

    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 ;
    std::cout << " and " << v2;
    std::cout << " is " << v1 * v2;
    std::cout << std::endl;

    return 0;
}
