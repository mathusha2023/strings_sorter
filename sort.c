#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "swap.h"

static int bubble_sort(char *arr[], size_t str_size, size_t arr_size);
static int my_quick_sort(char *arr[], size_t str_size, size_t arr_size, size_t left, size_t right);

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

    for (size_t pas = 0; pas < arr_size - 1; pas++)
    {
        for (size_t i = 0; i < arr_size - pas - 1; i++)
        {
            assert(pas < arr_size);
            assert(i < arr_size);

            if (compare_strings(arr[i], arr[i + 1], str_size) > 0)
            {
                // if (swap(arr[i], arr[i + 1], str_size)) // проверка на ошибку
                if (swap_by_pointers(&arr[i], &arr[i + 1])) // проверка на ошибку
                    return 1;
            }
        }
    }
    return 0;
}

static int my_quick_sort(char *arr[], size_t str_size,
                         size_t arr_size, size_t left, size_t right)
{
}