#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef HASH_MAP_H
#define HASH_MAP_H

typedef size_t (*hash_function)(void *key, size_t length);
typedef bool (*equality_function)(void *key_1, void *key_2);

typedef struct Node{
    void *key;
    size_t key_length;
    void *val;
    struct Node *next;
}Node;

typedef struct {
    Node **nodes_array;
    size_t size;
    size_t capacity;
}HashMap;

HashMap *initialize(size_t initial_size);

void put(
    HashMap *map,
    void *key,
    size_t key_length,
    hash_function hash,
    equality_function equals,
    void *val);

void *get(
    HashMap *map,
    void *key,
    size_t key_length,
    hash_function hash,
    equality_function equals);

void destroy(HashMap *map);

#endif
