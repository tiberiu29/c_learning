#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H
#include <stddef.h>
typedef struct StringBuilder StringBuilder;

StringBuilder *sb_initialize();
void append_char(StringBuilder *sb, char c);
void append_int(StringBuilder *sb, int n);
char *to_string(StringBuilder *sb);
size_t get_size(StringBuilder *sb);
void sb_clear(StringBuilder *sb);
void sb_destroy(StringBuilder *sb);
#endif
