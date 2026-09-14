#ifndef CONFIG_H
#define CONFIG_H

#include <stdlib.h>

#define free_ptr(p) \
    {               \
        free(p);    \
        p = NULL;   \
    }

const size_t STR_SIZE = 23;
const size_t ARR_SIZE = 5;

#endif // CONFIG_H
