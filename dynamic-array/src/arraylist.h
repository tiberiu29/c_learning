#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef struct {
    void* data;
    size_t size;
    size_t capacity;
    size_t element_size_bytes;
}ArrayList;


ArrayList *initialize(size_t initial_capacity, size_t element_size_bytes);

void *get(ArrayList *array_list, size_t index);

void push(ArrayList *array_list, void *element);

void *pop(ArrayList *array_list);

void add(ArrayList *array_list, size_t index, void *element);

void *remove_at(ArrayList *array_list, size_t index);

void destroy(ArrayList *array_list);

#endif 
