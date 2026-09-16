#include <string.h>
#include <assert.h>

int compare_strings(const void *a, const void *b)
{
    assert(a);
    assert(b);
    assert(a != b);

    return strcmp(*(const char **)a, *(const char **)b);
}