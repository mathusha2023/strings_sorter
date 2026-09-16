#include <stddef.h>

int swap(void *a, void *b, void *extra);
int swap_by_full_string(char *s1, char *s2, size_t size);
int swap_by_one_char(char *s1, char *s2, size_t size);
int swap_by_group_char(char *s1, char *s2, size_t size);
int swap_by_pointers(char **s1, char **s2);