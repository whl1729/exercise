#include <stdio.h>

union Data
{
    char ch;
    int i;
};

void byte_order_1()
{
    union Data data;
    data.i = 0x12345678;
    printf("%#x\n", data.ch);
    if (data.ch == 0x12)
    {
        printf("Big Endian.\n");
    }
    else if (data.ch == 0x78)
    {
        printf("Little Endian.\n");
    }
    else
    {
        printf("Error.\n");
    }
}

void byte_order_2()
{
    int i = 0x12345678;
    char ch = *(char *)&i;
    printf("%#x\n", ch);
    if (ch == 0x12)
    {
        printf("Big Endian.\n");
    }
    else if (ch == 0x78)
    {
        printf("Little Endian.\n");
    }
    else
    {
        printf("Error.\n");
    }
}

int main()
{
    byte_order_1();
    byte_order_2();

    return 0;
}
