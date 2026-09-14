#include "swap.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdalign.h>
#include <stdio.h>
#include "config.h"

static int swap_by_full_string(char *s1, char *s2, size_t size);
static int swap_by_one_char(char *s1, char *s2, size_t size);
static int swap_by_group_char(char *s1, char *s2, size_t size);

int swap(char *s1, char *s2, size_t size)
{
    assert(s1);
    assert(s2);
    assert(s1 != s2);

    // return swap_by_full_string(s1, s2, size);
    // return swap_by_one_char(s1, s2, size);
    return swap_by_group_char(s1, s2, size);
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

    free_ptr(p);

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

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-align"
#endif

// меняем местами по 8 байт символов строки за один заход
// для уменьшения числа обращений к ОЗУ
static int swap_by_group_char(char *s1, char *s2, size_t size)
{
    assert(s1);
    assert(s2);
    assert(s1 != s2);

    while (size >= sizeof(uint64_t))
    {
        uint64_t temp = *(uint64_t *)s1;
        *(uint64_t *)s1 = *(uint64_t *)s2;
        *(uint64_t *)s2 = temp;
        s1 += sizeof(uint64_t);
        s2 += sizeof(uint64_t);
        size -= sizeof(uint64_t);
    }

    if (size >= sizeof(uint32_t))
    {
        uint32_t temp = *(uint32_t *)s1;
        *(uint32_t *)s1 = *(uint32_t *)s2;
        *(uint32_t *)s2 = temp;
        s1 += sizeof(uint32_t);
        s2 += sizeof(uint32_t);
        size -= sizeof(uint32_t);
    }
    if (size >= 2)
    {
        uint16_t temp = *(uint16_t *)s1;
        *(uint16_t *)s1 = *(uint16_t *)s2;
        *(uint16_t *)s2 = temp;
        s1 += sizeof(uint16_t);
        s2 += sizeof(uint16_t);
        size -= sizeof(uint16_t);
    }
    if (size >= sizeof(char))
    {
        char temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        size -= sizeof(char);
    }
    return (int)size;
}

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif