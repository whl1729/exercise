// This program is used to check the return value of main:
// firstly we run this program, and then enter "echo $?" on the terminal.
#include <iostream>

int main(int argc, char *argv[])
{
    int num = 0;
    int pos = -1;
    int flag = 1;

    std::cout << "argc = " << argc << ", argv[0] = " << argv[0] << std::endl;

    if ((argc != 2) || (argv[0] == NULL))
    {
        std::cout << "Usage: a.out num" << std::endl;
        return -1;
    }

    std::cout << "argv[1] = " << argv[1] << std::endl;

    if (argv[1][0] == '-')
    {
        pos = 0;
        flag = -1;
    }

    while (argv[1][++pos])
    {
        num = 10 * num + (argv[1][pos] - '0');
    }

    num *= flag;

    std::cout << "The number you enter is " << num << std::endl;

    return num;
}
