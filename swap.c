#include "swap.h"
#include <string.h>
#include <stdlib.h>

static int swap_with_full_string(char *s1, char *s2, size_t size);
static int swap_by_one_char(char *s1, char *s2, size_t size);

int swap(char *s1, char *s2, size_t size)
{
    assert(s1);
    assert(s2);
    assert(s1 != s2);

    return swap_with_full_string(s1, s2, size);
}

static int swap_with_full_string(char *s1, char *s2, size_t size)
{
    assert(s1);
    assert(s2);
    assert(s1 != s2);

    char *p = (char *)calloc(size, sizeof(char));
    if (!p)
        return 1;

    strncpy(p, s1, size);  // в p лежит s1
    strncpy(s1, s2, size); // в s1 теперь s2
    strncpy(s2, p, size);  // в s2 теперь s1

    free(p);

    return 0;
}

static int swap_by_one_char(char *s1, char *s2, size_t size)
{
    assert(s1);
    assert(s2);
    assert(s1 != s2);

    for (size_t i = 0; i < size; i++)
    {
        char temp = s1[i];
        s1[i] = s2[i];
        s2[i] = temp;
    }

    return 0;
}