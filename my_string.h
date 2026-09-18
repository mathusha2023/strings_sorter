#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stddef.h>
#include <stdalign.h>

struct String
{
    const char *p;
    size_t length;
};

int chrcount(const char *str, char c);
int lines_count(const char *str);
struct String *make_strings_arr(const char *text, size_t *arr_length);

#endif