#ifndef LOG_H
#define LOG_H

#ifdef NDEBUG
#define DISABLE_LOGS
#endif // NDEBUG

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "config.h"

const size_t MAX_TIME_BUF = 100;

#define restart_log()                                    \
    {                                                    \
        FILE *zalupavanyfile = fopen(LOGFILE_NAME, "w"); \
        assert(zalupavanyfile);                          \
        fclose(zalupavanyfile);                          \
        zalupavanyfile = NULL;                           \
    }

#ifdef DISABLE_LOGS
#define log(message, ...)
#else
#define log(need_console, message, ...)                                                                         \
    {                                                                                                           \
        FILE *zalupavanyfile = fopen(LOGFILE_NAME, "a");                                                        \
        assert(zalupavanyfile);                                                                                 \
                                                                                                                \
        time_t zalupavanyseconds = time(NULL);                                                                  \
        struct tm *zalupavanytimeinfo = localtime(&zalupavanyseconds);                                          \
        char zalupavanybuf[MAX_TIME_BUF] = {};                                                                  \
        strftime(zalupavanybuf, MAX_TIME_BUF, "%d.%m.%g %H:%M:%S", zalupavanytimeinfo);                         \
                                                                                                                \
        if (need_console)                                                                                       \
            fprintf(stderr, "[%s] %s:%d: " message "\n", zalupavanybuf, __FILE__, __LINE__, ##__VA_ARGS__);     \
                                                                                                                \
        fprintf(zalupavanyfile, "[%s] %s:%d: " message "\n", zalupavanybuf, __FILE__, __LINE__, ##__VA_ARGS__); \
                                                                                                                \
        fclose(zalupavanyfile);                                                                                 \
        zalupavanyfile = NULL;                                                                                  \
    }
#endif // DISABLE_LOGS

#endif // LOG_H