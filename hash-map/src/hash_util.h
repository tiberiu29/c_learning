#include <stddef.h>
#ifndef HASH_UTIL_H
#define HASH_UTIL_H

size_t djb2_hash(void *key, size_t length);
size_t joaat_hash(void * key,size_t length);

#endif
