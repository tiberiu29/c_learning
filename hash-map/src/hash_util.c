#include <stddef.h>
#include "hash_util.h"

// implemented djb2 for hashing
const unsigned int MAGIC_CONSTANT_DJB2 = 5381;
size_t djb2_hash(void *key, size_t length){

    unsigned char* key_char = key;
    size_t i = 0;
    size_t hash = MAGIC_CONSTANT_DJB2;
    while(i != length) {
        char character = key_char[i++];
        hash = (hash << 5) + hash + character;
    }
    return hash; 
}

// implemented Jenkins One At A Time hash
size_t joaat_hash(
        void * key,
        size_t length) {

  unsigned char* key_char = key;
  size_t i = 0;
  size_t hash = 0;
  while (i != length) {
    hash += key_char[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash;
}
