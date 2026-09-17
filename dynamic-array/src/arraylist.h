#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
}ArrayList;


ArrayList *initialize(size_t initial_capacity);

int get(ArrayList *array_list, size_t index);

void push(ArrayList *array_list, int number);

int pop(ArrayList *array_list);

void add(ArrayList *array_list, size_t index, int value);

int remove_at(ArrayList *array_list, size_t index);

void destroy(ArrayList *array_list);

#endif 
