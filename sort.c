#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "log.h"

int bubble_sort(void *arr,
                size_t arr_length,
                size_t el_size,
                int (*comparator)(const void *a, const void *b),
                int (*swap)(void *a, void *b))
{
    assert(arr);
    assert(comparator);
    assert(swap);

    if (!arr_length)
        return 1;
    if (arr_length == 1)
        return 0;

    for (size_t pas = 0; pas < arr_length - 1; pas++)
    {
        for (size_t i = 0; i < arr_length - pas - 1; i++)
        {
            assert(pas < arr_length);
            assert(i < arr_length);

            void *a = (void *)((size_t)arr + el_size * i),
                 *b = (void *)((size_t)arr + el_size * (i + 1));

            if (comparator(a, b) > 0)
            {
                if (swap(a, b)) // проверка на ошибку
                {
                    log("Bubble sort: error while swapping: pas = %lu, i = %lu", pas, i);
                    return 1;
                }
            }
        }
        log("Bubble sort: pas = %lu/%lu", pas, arr_length - 2);
    }

    log("Bubble sorting complete!");
    return 0;
}
