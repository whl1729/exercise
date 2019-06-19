#include <stdio.h>

int g_apple = 0x11111111;
int g_bar = 0x22222222;
static int g_cat = 0x33333333;
int g_dog;
char hi[] = "Nice to meet u\n";

int main()
{
    static int l_egg = 0x55555555;
    static int l_foo = 0x66666666;
    int l_god = 0x77777777;
    int l_hey = 0x88888888;
    char greet[] = "Hello World\n";

    g_bar = 0x33333333;
    printf("g_apple=%d, g_bar=%d\n", g_apple, g_bar);
    printf("l_foo=%d, l_god=%d\n", l_foo, l_god);
    printf("%s", hi);
    printf("%s", greet);

    return 0;
}
