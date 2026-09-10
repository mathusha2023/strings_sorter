#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "swap.h"

static int bubble_sort(char *arr[], size_t str_size, size_t arr_size);

int sort(char *arr[], size_t str_size, size_t arr_size)
{
    assert(arr);

    return bubble_sort(arr, str_size, arr_size);
}

static int compare_strings(const char *s1, const char *s2, size_t size)
{
    assert(s1);
    assert(s2);
    assert(s1 != s2);

    return strncmp(s1, s2, size);
}

static int bubble_sort(char *arr[], size_t str_size, size_t arr_size)
{
    assert(arr);

    if (!arr_size)
        return 1;
    if (arr_size == 1)
        return 0;

    for (size_t i = 0; i < arr_size - 1; i++)
    {
        for (size_t j = 0; j < arr_size - i - 1; j++)
        {
            assert(i < arr_size);
            assert(j < arr_size);

            if (compare_strings(arr[j], arr[j + 1], str_size) > 0)
            {
                // if (swap(arr[j], arr[j + 1], str_size)) // проверка на ошибку
                //     return 1;
                if (swap_by_pointers(&arr[j], &arr[j + 1])) // проверка на ошибку
                    return 1;
            }
        }
    }
    return 0;
}