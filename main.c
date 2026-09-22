#include "main.h"
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
#include "cmd_args.h"
#include "log.h"

int main(int argc, char *argv[])
{
    restart_log();

    struct CmdArgs cmd_args = get_args(argc, argv);

    if (cmd_args.error)
    {
        log("Error in cmd line args: code %d", cmd_args.error);
        return 1;
    }

    const char *input_file_name = cmd_args.INPUT_FILE_NAME ? cmd_args.INPUT_FILE_NAME : DEFAULT_INPUT_FILE_NAME;
    const char *output_file_name = cmd_args.OUTPUT_FILE_NAME ? cmd_args.OUTPUT_FILE_NAME : DEFAULT_OUTPUT_FILE_NAME;

    log("Input file name: '%s'", input_file_name);
    log("Output file name: '%s'", output_file_name);

    int error = 0;

    printf("Starting Onegin rewriting!\n");

    char *buffer = get_file_text(input_file_name);
    if (!buffer)
    {
        log("Cant get file %s text((\n", input_file_name);
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

    printf("Onegin re-writing successful! Saved in %s\n", output_file_name);

    return 0;
}