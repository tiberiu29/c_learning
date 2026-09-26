#include <stddef.h>
#include <stdlib.h>
#ifndef HASH_MAP_H
#define HASH_MAP_H

typedef size_t (*hash_function)(void *key, size_t length);

typedef struct Node{
    void *key;
    void *val;
    struct Node *next;
}Node;

typedef struct {
    Node **nodes_array;
    size_t array_size;
    size_t array_capacity;
}HashMap;

HashMap *initialize();

void put(
    HashMap *map,
    void *key,
    size_t key_length,
    hash_function hash,
    void *val);

#endif
