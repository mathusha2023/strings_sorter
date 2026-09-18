#ifndef CONFIG_H
#define CONFIG_H

#include <stdlib.h>

#define RED_COLOR "\x1b[31m"
#define GREEN_COLOR "\x1b[32m"
#define BLUE_COLOR "\x1b[34m"
#define YELLOW_COLOR "\x1b[33m"
#define CYAN_COLOR "\x1b[36m"
#define GREY_COLOR "\033[90m"
#define RESET_COLOR "\x1b[0m"

#define free_ptr(p) \
    {               \
        free(p);    \
        p = NULL;   \
    }

const char DEFAULT_INPUT_FILE_NAME[] = "formatted_onegin.txt";
const char DEFAULT_OUTPUT_FILE_NAME[] = "0N3G1N.txt";
const char LOGFILE_NAME[] = "log.txt";

#endif // CONFIG_H
