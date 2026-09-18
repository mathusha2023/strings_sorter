#include <stddef.h>

int read_text(const char *filename, char **text);
int write_text(const char *filename, char **text, size_t size, const char *mode);
int write_line(const char *filename, const char *line, const char *mode);
void free_arr(char **text, size_t size);
char *mystrdup(const char *str);