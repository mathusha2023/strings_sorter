#include "swap.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

static int swap_by_full_string(char *s1, char *s2, size_t size);
static int swap_by_one_char(char *s1, char *s2, size_t size);
static int swap_by_group_char(char *s1, char *s2, size_t size);

int swap(char *s1, char *s2, size_t size)
{
    assert(s1);
    assert(s2);
    assert(s1 != s2);

    return swap_by_full_string(s1, s2, size);
    // return swap_by_one_char(s1, s2, size);
    // return swap_by_group_char(s1, s2, size);
}

int swap_by_pointers(char **s1, char **s2)
{
    assert(s1);
    assert(s2);
    assert(s1 != s2);
    assert(*s1);
    assert(*s2);
    assert(*s1 != *s2);

    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;

    return 0;
}

static int swap_by_full_string(char *s1, char *s2, size_t size)
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

static int swap_by_group_char(char *s1, char *s2, size_t size)
{
    assert(s1);
    assert(s2);
    assert(s1 != s2);

    char *s1c = s1, *s2c = s2;

    while (size >= 8)
    {
        unsigned long long temp = *(unsigned long long *)s1;

        printf("Before: s1 = <%s>, s2 = <%s>\n", s1c, s2c);

        *(unsigned long long *)(size_t)s1 = *(unsigned long long *)s2;
        *(unsigned long long *)(size_t)s2 = temp;

        printf("After: s1 = <%s>, s2 = <%s>\n", s1c, s2c);

        s1 += 8;
        s2 += 8;
        size -= 8;
    }

    if (size >= 4)
    {
        unsigned temp = *(unsigned *)s1;
        *(unsigned *)s1 = *(unsigned *)s2;
        *(unsigned *)s2 = temp;
        s1 += 4;
        s2 += 4;
        size -= 4;
    }
    if (size >= 2)
    {
        unsigned short temp = *(unsigned short *)s1;
        *(unsigned short *)s1 = *(unsigned short *)s2;
        *(unsigned short *)s2 = temp;
        s1 += 2;
        s2 += 2;
        size -= 2;
    }
    if (size >= 1)
    {
        char temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        size -= 1;
    }
    return (int)size;
}
