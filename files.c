#include "files.h"
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include "config.h"

int read_text(const char *filename, char **text)
{
    assert(filename);
    assert(text);

    FILE *file = fopen(filename, "r");
    if (!file)
        return errno;

    char buf[MAX_STRING_LENGTH] = {};
    size_t i = 0;

    while (fgets(buf, MAX_STRING_LENGTH, file) != NULL)
    {
        char *p = mystrdup(buf);
        if (!p)
            return errno;
        text[i++] = p;
    }

    if (feof(file))
    {
        fclose(file);
        return 0;
    }

    fclose(file);
    return errno;
}

int write_text(const char *filename, char **text, size_t size, const char *mode)
{
    assert(filename);
    assert(text);
    assert(mode);

    FILE *file = fopen(filename, mode);
    if (!file)
        return errno;

    for (size_t i = 0; i < size; i++)
    {
        if (!text[i])
            break;

        if (fprintf(file, "%s", text[i]) < 0)
        {
            fclose(file);
            return errno;
        }
    }

    fclose(file);
    return 0;
}

int write_line(const char *filename, const char *line, const char *mode)
{
    assert(filename);
    assert(line);
    assert(mode);

    FILE *file = fopen(filename, mode);
    if (!file)
        return errno;

    if (fprintf(file, "%s", line) < 0)
    {
        fclose(file);
        return errno;
    }

    fclose(file);
    return 0;
}

void free_arr(char **text, size_t size)
{
    assert(text);

    for (size_t i = 0; i < size; i++)
        free_ptr(text[i]);
}

char *mystrdup(const char *str)
{
    assert(str);

    size_t length = strlen(str);

    char *p = (char *)calloc(length + 1, sizeof(char));
    if (!p)
        return NULL;

    strncpy(p, str, length + 1);
    return p;
}