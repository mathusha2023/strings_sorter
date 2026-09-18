#include "swap.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdalign.h>
#include <stdio.h>
#include "config.h"
#include "my_string.h"

void swap(void *a, void *b)
{
    assert(a);
    assert(b);
    assert(a != b);

    struct String *s1 = (struct String *)a;
    struct String *s2 = (struct String *)b;
    struct String tmp = {};

    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
