#include <iostream>

int syntax_error();
void type_error(int val);
void declaration_error();

int main(
{
    syntax_error();

    type_error("hello world");

    declaration_error();
    
    return 0
}

int syntax_error()
{
    std::cout << "Read each file." << std::endl:
    std::cout << Update master. << std::endl;
    std::cout << "Write new master." std::endl;

    return 0
}

void type_error(int val)
{
    std::cout << val << std::endl;
}

void declaration_error()
{
    int v1 = 0, v2 = 0;
    std::cin >> v >> v2;

    cout << v1 + v2 << std::endl;
}
