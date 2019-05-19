#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE  500000
#define TEST_TIME 5

void quick_sort(int *arr, int left, int right);
void quick_sort_hoare(int *arr, int left, int right);
int whl_partition_1(int *arr, int left, int right);
int whl_partition_2(int *arr, int left, int right);
int lomuto_partition(int *arr, int left, int right);
int hoare_partition(int *arr, int left, int right);
void print_arr(int *arr, int num);

typedef int (*pfunc)(int *arr, int left, int right);
typedef void (*psfunc)(int *arr, int left, int right);

pfunc partition;

int main()
{
    int arr[SIZE];
    int pos, id, test;
    double cur_time, avg_time;
    clock_t start_t, end_t;
    pfunc func_tbl[] = {whl_partition_1,
                        whl_partition_2,                    
                        lomuto_partition,
                        hoare_partition,
    };
    psfunc sort;

    srand((unsigned)time(0));

    for (id = 0; id < sizeof(func_tbl) / sizeof(pfunc); id++)
    {
        printf("\nNow test quick_sort algorithm %d...\n", id);
        partition = func_tbl[id];
        sort = (id < 3)? quick_sort : quick_sort_hoare;
        avg_time = 0;

        for (test = 0; test < TEST_TIME; test++)
        {
            for (pos = 0; pos < SIZE; pos++)
                arr[pos] = rand() % 10000;

            // print_arr(arr, SIZE);

            start_t = clock();

            sort(arr, 0, SIZE - 1);

            end_t = clock();

            cur_time = (double) (end_t - start_t) / CLOCKS_PER_SEC;
            avg_time += cur_time;
            // print_arr(arr, SIZE);

            printf("spend time: %f\n", cur_time);
        }
        
        printf("\naverage time: %f\n", avg_time / TEST_TIME);
    }

    return 0;
}

int whl_partition_1(int *arr, int left, int right)
{
    int pivot = (left + right) / 2;
    int tmp;

    if (left < pivot)
    {
        tmp = arr[left];
        arr[left] = arr[pivot];
        arr[pivot] = tmp;
    }

    int start = left + 1;
    int end = right;
    int pos;

    while (start <= end)
    {
        if (arr[start] <= arr[left])
            start++;
        else
        {
            tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
            end--;
        }
    }

    pos =  (start < end)? start : end;

    tmp = arr[left];
    arr[left] = arr[pos];
    arr[pos] = tmp;

    return pos;
}

int whl_partition_2(int *arr, int left, int right)
{
    int pivot = (left + right) / 2;
    int tmp;

    if (left < pivot)
    {
        tmp = arr[left];
        arr[left] = arr[pivot];
        arr[pivot] = tmp;
    }

    int start = left + 1;
    int end = right;
    int pos;

    while (start <= end)
    {
        while ((start <= end) && (arr[start] <= arr[left]))
            start++;

        while ((start <= end) && (arr[end] >= arr[left]))
            end--;

        if (start < end)
        {
            tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
            start++;
            end--;
        }
    }

    tmp = arr[left];
    arr[left] = arr[end];
    arr[end] = tmp;

    return end;
}

int lomuto_partition(int *arr, int left, int right)
{
    int pivot = arr[right];
    int pos, tmp;
    int idx = left; // arr[left..idx-1] aren't greater than pivot.

    for (pos = left; pos < right; pos++)
    {
        if (arr[pos] < pivot)
        {
            tmp = arr[idx];
            arr[idx] = arr[pos];
            arr[pos] = tmp;
            idx++;
        }
    }

    arr[right] = arr[idx];
    arr[idx] = pivot;

    return idx;
}

int hoare_partition(int *arr, int left, int right)
{
    int pivot = arr[(left + right)/2];
    int start = left - 1;
    int end = right + 1;
    int tmp;

    while (1)
    {
        while (arr[++start] < pivot);

        while (arr[--end] > pivot);

        if (start >= end)
            return end;

        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
    }
}

void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pos = partition(arr, left, right);
        quick_sort(arr, left, pos-1);
        quick_sort(arr, pos+1, right);
    }
}

void quick_sort_hoare(int *arr, int left, int right)
{
    if (left < right)
    {
        int pos = partition(arr, left, right);
        quick_sort_hoare(arr, left, pos);
        quick_sort_hoare(arr, pos+1, right);
    }
}

void print_arr(int *arr, int num)
{
    int pos;

    for (pos = 0; pos < num; pos++)
        printf("%d ", arr[pos]);

    printf("\n");
}
