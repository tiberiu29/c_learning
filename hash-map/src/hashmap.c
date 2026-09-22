#include <stddef.h>
#include "hashmap.h"

int MAGIC_CONSTANT = 5381;

// implemented djb2 for hashing
size_t hash_string(char *c){
    int i = 0;
    size_t hash = MAGIC_CONSTANT;
    while(*(c+i) != '\0') {
        char character = *(c+i);
        hash = (hash << 5) + hash + character;
        i++;
    }
    return hash; 
}

