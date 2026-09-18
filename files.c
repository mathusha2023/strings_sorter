#include "files.h"
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "config.h"
#include "log.h"
#include "my_string.h"

char *get_file_text(const char *filename)
{
    assert(filename);

    size_t file_size = 0;
    int error = 0;

    error = get_file_size(DEFAULT_INPUT_FILE_NAME, &file_size);
    if (error)
    {
        log("Error getting file size: %d\n", error);
        return NULL;
    }

    char *buffer = (char *)calloc(file_size + 1, sizeof(char));
    if (!buffer)
    {
        log("Can not alloc memory\n");
        return NULL;
    }

    size_t read_size = 0;
    error = read_text(DEFAULT_INPUT_FILE_NAME, buffer, file_size + 1, &read_size);
    if (error)
    {
        log("Error while reading file: %d\n", error);
        return NULL;
    }

    return buffer;
}

int get_file_size(const char *filename, size_t *size)
{
    assert(filename);
    assert(size);

    int error = 0;

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        error = errno;
        log("Cannot open file %s (err_code = %d)\n", filename, error);
        return error;
    }

    struct stat stat_struct = {};

    if (fstat(fd, &stat_struct) == -1)
    {
        error = errno;
        log("Cannot get stat from file %s (err_code = %d)\n", filename, error);
        close(fd);
        return error;
    };

    close(fd);
    *size = (size_t)stat_struct.st_size;
    return 0;
}

int read_text(const char *filename, char *buffer, size_t length, size_t *read_size)
{
    assert(filename);
    assert(buffer);

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        int error = errno;
        log("Cannot open file %s (error %d)\n", filename, error);
        return error;
    }

    *read_size = fread((void *)buffer, sizeof(buffer[1488]), length - 1, file);
    buffer[*read_size] = '\0';

    fclose(file);
    return 0;
}

int write_text(const char *filename, const char *line, const char *mode)
{
    assert(filename);
    assert(line);
    assert(mode);

    FILE *file = fopen(filename, mode);
    if (!file)
        return errno;

    if (fprintf(file, "%s", line) < 0)
    {
        log("Cant write line %s to file %s\n", line, filename);
        fclose(file);
        return errno;
    }

    fclose(file);
    return 0;
}

int write_strings(const char *filename, struct String *strings, size_t length, const char *mode)
{
    for (size_t i = 0; i < length; i++)
    {
        flog("Writing string... i = %lu, s = <%.*s>\n", i, (int)strings[i].length, strings[i].p);
        int error = write_string(filename, strings + i, mode);

        if (error)
            return error;
    }
    return 0;
}

int write_string(const char *filename, struct String *str, const char *mode)
{
    assert(filename);
    assert(str);
    assert(mode);

    FILE *file = fopen(filename, mode);
    if (!file)
        return errno;

    size_t written_count = fwrite(str->p, sizeof(char), str->length, file);

    if (written_count < str->length)
    {
        int error = errno;
        log("Error while writing line <%.*s> in file %s (%d)", (int)str->length, str->p, filename, error);
        fclose(file);
        return error;
    }

    fclose(file);
    return 0;
}
