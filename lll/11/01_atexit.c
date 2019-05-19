#include <stdio.h>
#include <stdlib.h>

void foo(void)
{
    printf("bye~foo~\n");
}

void bar(void)
{
    printf("bye~bar~\n");
}

int main()
{
    atexit(&foo);
    atexit(&bar);

    printf("endof main\n");

    return 0;
}
