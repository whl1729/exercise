#include "stdio.h"

#define BIT_LEN  32
#define uint    unsigned int

void num2bits(uint num, char *bits);
uint rightrot(uint x, int n);

int main()
{
    uint x, result;
    int n;
    int go_on = 1; 
    char bits[BIT_LEN + 1];

    while (go_on)
    {
        x = n = 0;

        printf("Enter x = ");
        scanf("%u", &x);

        printf("Enter n = ");
        scanf("%d", &n);

        result = rightrot(x, n); 

        num2bits(x, bits);
        printf("x = %u\r\n(%s)\r\n", x, bits);

        num2bits(result, bits);
        printf("result = %u\r\n(%s)\r\n", result, bits);

        printf("Enter 0 to quit, 1 to go on: ");
        scanf("%d", &go_on);
    }

    return 0;
}

uint rightrot(uint x, int n)
{
    uint mask;
    
    while (n--)
    {
        mask = x & 1;
        x >>= 1;
        x |= (mask << (BIT_LEN - 1));
    }

    return x;
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
