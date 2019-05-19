#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  NUM  10
#define  ROT  4

void rotate(int *arr, int left, int right);

int main()
{
    int i, j;
    int arr[NUM];

    srand(time(0));

    printf("arr:\n");

    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < NUM; i++)
        {
            arr[i] = rand() % NUM + 1;

            printf("%d ", arr[i]);
        }

        printf("\nafter left rotate %d elemets, now the arr:\n", ROT);

        rotate(arr, 0, ROT - 1);

        rotate(arr, ROT, NUM - 1);

        rotate(arr, 0, NUM - 1);

        for (i = 0; i < NUM; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }

    return 0;
}

void rotate(int *arr, int left, int right)
{
    int tmp;

    while (left < right)
    {
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] =tmp;

        left++;
        right--;
    }
}
