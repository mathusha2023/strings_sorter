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

#define write_t(text, mode)                                       \
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

    write_t("0N3G1N by mc BAA\n\n", "w");

    write_t("\nPart 1. Sorted\n------------------------\n\n", "a");

    if (bubble_sort((void *)strings, strings_count, sizeof(strings[0]), &my_compare, &swap))
    {
        log("Error while sorting");
        free_ptr(strings);
        free_ptr(buffer);
        return 1;
    };

    error = write_strings(DEFAULT_OUTPUT_FILE_NAME, strings, strings_count, "a");
    if (error)
    {
        log("Cant write string (%d)\n", error);
        free_ptr(strings);
        free_ptr(buffer);
        return error;
    }

    write_t("\n\nPart 2. mc Pushkaas\n------------------------\n\n", "a");

    if (bubble_sort((void *)strings, strings_count, sizeof(strings[0]), &my_compare_reversed, &swap))
    {
        log("Error while sorting");
        free_ptr(strings);
        free_ptr(buffer);
        return 1;
    };

    error = write_strings(DEFAULT_OUTPUT_FILE_NAME, strings, strings_count, "a");
    if (error)
    {
        log("Cant write string (%d)\n", error);
        free_ptr(strings);
        free_ptr(buffer);
        return error;
    }

    write_t("\n\nPart 3. A. S. Pushkin \"Eugene Onegin\"\n------------------------\n\n", "a");

    write_t(buffer, "a");

    write_t("\nOnegin vse!\nVot i ckazochki konez, a kto slushal - molodez!\n", "a");

    free_ptr(strings);
    free_ptr(buffer);

    printf("Onegin re-writing successful! Saved in %s\n", DEFAULT_OUTPUT_FILE_NAME);

    return 0;
}