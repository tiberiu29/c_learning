#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
}ArrayList;

int get(ArrayList *array_list, size_t index);

ArrayList *initialize(size_t initial_capacity);

void push(ArrayList *array_list, int number);

int pop(ArrayList *array_list);

void destroy(ArrayList *array_list);
#endif 
