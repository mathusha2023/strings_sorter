#include "compare.h"
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include "log.h"
#include "my_string.h"

int my_compare(const void *a, const void *b)
{
    assert(a);
    assert(b);
    assert(a != b);

    const struct String *s1 = (const struct String *)a;
    const struct String *s2 = (const struct String *)b;

    size_t i = 0, j = 0;

    while (i < s1->length && j < s2->length)
    {
        while (i < s1->length && !isalpha(s1->p[i]))
            i++;
        while (j < s2->length && !isalpha(s2->p[j]))
            j++;

        // после циклов в каждой строке нашли либо букву, либо она кончилась
        assert((i == s1->length || isalpha(s1->p[i])) && (j == s2->length || isalpha(s2->p[j])));

        if (i == s1->length && j == s2->length)
            return 0;
        if (i == s1->length)
            return 1;
        if (j == s2->length)
            return -1;

        assert(isalpha(s1->p[i]) && isalpha(s2->p[j]));

        int diff = tolower(s1->p[i]) - tolower(s2->p[j]);

        if (diff != 0)
            return diff;

        i++, j++;
    }

    if (i == s1->length && j == s2->length)
        return 0;
    if (i == s1->length)
        return 1;
    return -1;
}

int my_compare_reversed(const void *a, const void *b)
{
    assert(a);
    assert(b);
    assert(a != b);

    const struct String *s1 = (const struct String *)a;
    const struct String *s2 = (const struct String *)b;

    // int, т.к. переменные могут стать отрицательными (при уменьшении и переходе через 0)
    int i = (int)s1->length - 1,
        j = (int)s2->length - 1;

    while (i >= 0 && j >= 0)
    {
        while (i >= 0 && !isalpha(s1->p[i]))
            i--;
        while (j >= 0 && !isalpha(s2->p[j]))
            j--;

        // после циклов s1[i] и s2[j] либо буквы, либо переменные i j отрицательные
        assert((i < 0 || isalpha(s1->p[i])) && (j < 0 || isalpha(s2->p[j])));

        if (i < 0 && j < 0)
            return 0;
        if (i < 0)
            return 1;
        if (j < 0)
            return -1;

        assert(isalpha(s1->p[i]) && isalpha(s2->p[j]));

        int diff = tolower(s1->p[i]) - tolower(s2->p[j]);

        if (diff != 0)
            return diff;

        i--, j--;
    }

    if (i < 0 && j < 0)
        return 0;
    if (i < 0)
        return 1;
    return -1;
}

int my_compare_by_pointer_value(const void *a, const void *b)
{
    assert(a);
    assert(b);
    assert(a != b);

    const size_t p1 = (size_t)a, p2 = (size_t)b;

    return p1 > p2 ? 1 : -1;
}