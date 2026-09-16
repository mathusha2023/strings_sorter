#include <stdio.h>
#include <stdalign.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "swap.h"
#include "compare.h"
#include "config.h"

void print_arr(char *arr[], size_t size);

int main(void)
{
    const char strings[ARR_SIZE][STR_SIZE] = {"MY", "WHEN", "HE", "AND", "HIS"};
    char *arr[ARR_SIZE] = {};

    for (size_t i = 0; i < ARR_SIZE; i++)
    {
        char *p = (char *)calloc(STR_SIZE, sizeof(char));
        if (!p)
            return 1;
        strncpy(p, strings[i], STR_SIZE);
        arr[i] = p;
    }

    print_arr(arr, ARR_SIZE);
    printf("\n");

    if (bubble_sort((void *)arr, ARR_SIZE, sizeof(char *), &compare_strings, &swap))
        return 1;

    printf("\n");
    print_arr(arr, ARR_SIZE);

    for (size_t i = 0; i < ARR_SIZE; i++)
        free_ptr(arr[i]);

    return 0;
}

void print_arr(char *arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf("String [%lu] = <%s>\n", i, arr[i]);
}