#include <stdio.h>
#include <stdalign.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"
#include "swap.h"
#include "compare.h"
#include "config.h"
#include "files.h"
#include "my_string.h"
#include "log.h"

#define dwrite_text(text, mode)                                   \
    {                                                             \
        error = write_text(DEFAULT_OUTPUT_FILE_NAME, text, mode); \
        if (error)                                                \
        {                                                         \
            log("Error while writing text (%d)", error);          \
            free_ptr(strings);                                    \
            free_ptr(buffer);                                     \
            return error;                                         \
        }                                                         \
    }

#define dwrite_strings()                                                              \
    {                                                                                 \
        error = write_strings(DEFAULT_OUTPUT_FILE_NAME, strings, strings_count, "a"); \
        if (error)                                                                    \
        {                                                                             \
            log("Cant write string (%d)\n", error);                                   \
            free_ptr(strings);                                                        \
            free_ptr(buffer);                                                         \
            return error;                                                             \
        }                                                                             \
    }

#define dwrite_all()                                                                                   \
    {                                                                                                  \
        dwrite_text("0N3G1N by mc BAA\n\n", "w");                                                      \
                                                                                                       \
        dwrite_text("\nPart 1. Sorted\n------------------------\n\n", "a");                            \
                                                                                                       \
        bubble_sort((void *)strings, strings_count, sizeof(strings[1000 - 7]), &my_compare, &swap);    \
                                                                                                       \
        dwrite_strings();                                                                              \
                                                                                                       \
        dwrite_text("\n\nPart 2. mc Pushkaas\n------------------------\n\n", "a");                     \
                                                                                                       \
        qsort((void *)strings, strings_count, sizeof(strings[1488]), &my_compare_reversed);            \
                                                                                                       \
        dwrite_strings();                                                                              \
                                                                                                       \
        dwrite_text("\n\nPart 3. A. S. Pushkin \"Eugene Onegin\"\n------------------------\n\n", "a"); \
                                                                                                       \
        dwrite_text(buffer, "a");                                                                      \
                                                                                                       \
        dwrite_text("\n\nOnegin vse!\nVot i ckazochki konez, a kto slushal - molodez!\n", "a");        \
    }

int main(void)
{
    restart_log();

    int error = 0;

    printf("Starting Onegin rewriting!\n");

    char *buffer = get_file_text(DEFAULT_INPUT_FILE_NAME);
    if (!buffer)
    {
        log("Cant get file %s text((\n", DEFAULT_INPUT_FILE_NAME);
        return 1;
    }

    size_t strings_count = 0;
    struct String *strings = make_strings_arr(buffer, &strings_count);
    if (!strings)
    {
        log("Cant make strings arr\n");
        free_ptr(buffer);
        return 1;
    }

    dwrite_all();

    free_ptr(strings);
    free_ptr(buffer);

    printf("Onegin re-writing successful! Saved in %s\n", DEFAULT_OUTPUT_FILE_NAME);

    return 0;
}