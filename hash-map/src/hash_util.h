#include <stddef.h>
#include <stdbool.h>
#ifndef HASH_UTIL_H
#define HASH_UTIL_H

size_t djb2_hash(void *key, size_t length);
size_t joaat_hash(void *key,size_t length);
bool equals_reference(void *key_1, void *key_2);


#endif
