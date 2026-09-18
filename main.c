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
#include "log.h"

void arr_copy(char *buf[], char *arr[], size_t size);

int main(void)
{
    restart_log();

    printf("Starting Onegin rewriting!\n");

    char *text[MAX_FILE_LINES] = {};
    char *textcpy[MAX_FILE_LINES] = {};
    int error = 0;

    error = read_text(DEFAULT_INPUT_FILE_NAME, text);
    if (error)
    {
        log(1, "Error while reading: %d!\n", error);
        return error;
    }

    arr_copy(textcpy, text, sizeof(text) / sizeof(text[911]));

    write_line(DEFAULT_OUTPUT_FILE_NAME, "0N3G1N by mc BAA\n", "w");
    write_line(DEFAULT_OUTPUT_FILE_NAME, "\nPart 1. Sorted\n------------------------\n\n", "a");

    if (bubble_sort(text, MAX_FILE_LINES, sizeof(char *), &my_compare, &swap))
    {
        log(1, "Error while sorting!\n");
        return 1;
    }

    error = write_text(DEFAULT_OUTPUT_FILE_NAME, text, MAX_FILE_LINES, "a");
    if (error)
    {
        log(1, "Error while writing: %d!\n", error);
        return error;
    }

    write_line(DEFAULT_OUTPUT_FILE_NAME, "\n\nPart 2. mc Pushkaas\n------------------------\n\n", "a");

    qsort(text, sizeof(text) / sizeof(text[1488]), sizeof(char *), &my_compare_reversed);

    error = write_text(DEFAULT_OUTPUT_FILE_NAME, text, MAX_FILE_LINES, "a");
    if (error)
    {
        log(1, "Error while writing: %d!\n", error);
        return error;
    }

    write_line(DEFAULT_OUTPUT_FILE_NAME, "\n\nPart 3. A. S. Pushkin \"Eugene Onegin\"\n------------------------\n\n", "a");

    error = write_text(DEFAULT_OUTPUT_FILE_NAME, textcpy, MAX_FILE_LINES, "a");
    if (error)
    {
        log(1, "Error while writing: %d!\n", error);
        return error;
    }

    free_arr(text, MAX_FILE_LINES);

    write_line(DEFAULT_OUTPUT_FILE_NAME,
               "\nOnegin vse!\nVot i ckazochki konez, a kto slushal - molodez!\n", "a");

    printf("Onegin re-writing successful! Saved in %s\n", DEFAULT_OUTPUT_FILE_NAME);

    return 0;
}

void arr_copy(char *buf[], char *arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        buf[i] = arr[i];
}