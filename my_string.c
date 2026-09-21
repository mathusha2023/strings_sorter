#include "my_string.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "log.h"

int chrcount(const char *str, char c)
{
    assert(str);

    int count = 0;
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == c)
            count++;
    }
    return count;
}

int lines_count(const char *str)
{
    assert(str);

    return chrcount(str, '\n') + 1;
}

struct String *make_strings_arr(const char *text, size_t *arr_length)
{
    assert(text);

    int lines_c = lines_count(text);
    *arr_length = 0; // отдельный счетчик для обработки случая, когда после последнего \n идет \0

    struct String *arr = (struct String *)calloc((size_t)lines_c, sizeof(struct String));
    if (!arr)
    {
        int error = errno;
        log("Cant allocate memory: error %d((\n", error);
        return NULL;
    }

    const char *start_p = text;
    size_t i = 0, j = 0;

    for (i = 0, j = 0; text[i]; i++)
    {
        if (text[i] == '\n')
        {
            struct String string = {.p = start_p, .length = (size_t)(text + i + 1 - start_p)};
            log("Struct string pointer: %p", &string);
            arr[j++] = string;
            log("Text pointer from string: %p", string.p);
            log("Arr pointer: %p", arr + j - 1);
            log("Text pointer from arr: %p\n", (arr + j - 1)->p);
            start_p = text + i + 1;
            log("Start pointer at <%c, %d> char\n", *start_p, (int)*start_p);
            (*arr_length)++;
        }
    }

    // только если после последнего перевода строки все еще есть строка добавляем ее
    if (*start_p)
    {
        log("HUIII\n");
        log("Start pointer after and loop: <%s>\n", start_p);
        (*arr_length)++;

        // без добавления 1, чтобы строка не заканчивалась на \0
        struct String string = {.p = start_p, .length = (size_t)(text + i - start_p)};
        log("The last char of string is <%c, %d>", string.p[string.length - 1], (int)string.p[string.length - 1]);
        arr[j] = string;
    }

    return arr;
}