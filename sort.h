#include <stddef.h>

void bubble_sort(void *arr,
                 size_t arr_length,
                 size_t el_size,
                 int (*comparator)(const void *a, const void *b),
                 void (*swap)(void *a, void *b));
