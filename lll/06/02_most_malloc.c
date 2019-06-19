#include <stdio.h>
#include <stdlib.h>

unsigned max = 0;

int main()
{
    unsigned size[] = {1024 * 1024, 1024, 1};
    int i, count;
    for (i = 0; i < 3; ++i)
    {
        for (count = 1; ; ++count)
        {
            void *block = malloc(max + size[i] * count);
            if (block)
            {
                max += size[i] * count;
            }
            else
            {
                break;
            }
        }
    }
    printf("max malloc size = %u bytes\n", max);

    return 0;
}
