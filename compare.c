#include "compare.h"
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include "log.h"

int compare_strings(const void *a, const void *b)
{
    assert(a);
    assert(b);
    assert(a != b);

    return strcmp(*(const char *const *)a, *(const char *const *)b);
}

int my_compare(const void *a, const void *b)
{
    assert(a);
    assert(b);
    assert(a != b);

    const char *s1 = *(const char *const *)a;
    const char *s2 = *(const char *const *)b;

    size_t i = 0, j = 0;

    while (s1[i] && s2[j])
    {
        while (s1[i] && !isalpha(s1[i]))
            i++;
        while (s2[j] && !isalpha(s2[j]))
            j++;

        // после циклов в каждой строке нашли либо букву, либо \0
        assert((isalpha(s1[i]) || s1[i] == '\0') && (isalpha(s2[j]) || s2[j] == '\0'));

        if (!s1[i] || !s2[j])
            return s1[i] - s2[j];

        assert(isalpha(s1[i]) && isalpha(s2[j]));

        if (tolower(s1[i]) != tolower(s2[j]))
            return tolower(s1[i]) - tolower(s2[j]);

        i++, j++;
    }

    return s1[i] - s2[j];
}

int my_compare_reversed(const void *a, const void *b)
{
    assert(a);
    assert(b);
    assert(a != b);

    const char *s1 = *(const char *const *)a;
    const char *s2 = *(const char *const *)b;

    // int, т.к. переменные могут стать отрицательными (при уменьшении и переходе через 0)
    int i = (int)strlen(s1) - 1,
        j = (int)strlen(s2) - 1;

    while (i >= 0 && j >= 0)
    {
        while (i >= 0 && !isalpha(s1[i]))
            i--;
        while (j >= 0 && !isalpha(s2[j]))
            j--;

        // после циклов s1[i] и s2[j] либо буквы, либо переменные i j отрицательные
        assert((i < 0 || isalpha(s1[i])) && (j < 0 || isalpha(s2[j])));

        if (i < 0 && j < 0)
            return 0;
        if (i < 0)
            return 1;
        if (j < 0)
            return -1;

        assert(isalpha(s1[i]) && isalpha(s2[j]));

        if (tolower(s1[i]) != tolower(s2[j]))
            return tolower(s1[i]) - tolower(s2[j]);

        i--, j--;
    }

    if (i < 0 && j < 0)
        return 0;
    if (i < 0)
        return 1;
    return -1;
}