#include <stdio.h>
#include "sort.h"

void print_arr(char *arr[], size_t size);

int main(void)
{
    const size_t STR_SIZE = 7;
    const size_t ARR_SIZE = 5;

    char strings[ARR_SIZE][STR_SIZE] = {"MY", "WHEN", "HE", "AND", "HIS"};
    char *arr[ARR_SIZE] = {};

    for (size_t i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = strings[i];
    }

    print_arr(arr, ARR_SIZE);
    printf("\n");

    if (sort(arr, STR_SIZE, ARR_SIZE))
        return 1;

    printf("\n");
    print_arr(arr, ARR_SIZE);

    return 0;
}

void print_arr(char *arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("String [%lu] = <%s>\n", i, arr[i]);
    }
}