#include "stdio.h"

#define BIT_LEN  32
#define uint    unsigned int

void num2bits(uint num, char *bits);
uint setbits(uint x, int p, int n, uint y);

int main()
{
    uint x, y, result;
    int p, n;
    int go_on = 1; 
    char bits[BIT_LEN + 1];

    while (go_on)
    {
        x = p = n = y = 0;

        printf("Enter x = ");
        scanf("%u", &x);

        printf("Enter y = ");
        scanf("%u", &y);

        printf("Enter p = ");
        scanf("%d", &p);

        printf("Enter n = ");
        scanf("%d", &n);

        result = setbits(x, p, n, y); 

        num2bits(x, bits);
        printf("x = %u(%s)\r\n", x, bits);

        num2bits(y, bits);
        printf("y = %u(%s)\r\n", y, bits);

        num2bits(result, bits);
        printf("result = %u(%s)\r\n", result, bits);

        printf("Enter 0 to quit, 1 to go on: ");
        scanf("%d", &go_on);
    }

    return 0;
}

uint setbits(uint x, int p, int n, uint y)
{
    uint mask = (((uint)(~0 << (BIT_LEN - 1 - p))) >> (BIT_LEN - n)) << (p - n + 1);
    return ((x & (~mask)) | (y & mask));
}

void num2bits(uint num, char *bits)
{
    int pos;

    for (pos = BIT_LEN - 1; pos >= 0; pos--)
    {
        bits[pos] = '0' + (num & 1);
        num >>= 1;
    }

    bits[BIT_LEN] = 0;
}
