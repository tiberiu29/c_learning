#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

int get(ArrayList *array_list, size_t index) {
    if(index >=  array_list->size) {
        printf("Index out of bounds");
        exit(1);
    }

    return array_list->data[index];
}

ArrayList *initialize(size_t initial_capacity) {
    int *data = malloc(initial_capacity * sizeof(int));

    if(data == NULL) {
        printf("Could not initialize data for ArrayList");
        exit(1);
    }

    ArrayList *array_list = malloc(sizeof(ArrayList));

    if(array_list == NULL) {
        printf("Could not initialize ArrayList");
        free(data);
        exit(1);
    }

    array_list->data = data;
    array_list->size = 0;
    array_list->capacity = initial_capacity;

    return array_list;
    
}

void push(ArrayList *array_list, int number) {
    if(array_list->size == array_list->capacity) {
        size_t current_capacity_int = array_list->capacity;
        size_t current_capacity_bytes =  current_capacity_int * sizeof(int);

        int* realloc_data = 
            realloc(array_list->data, current_capacity_bytes * 2 );

        if(realloc_data == NULL) {
            printf("Could not reallocate array for size increase");
            exit(1);
        }
    
        array_list->data = realloc_data;
        array_list->capacity = current_capacity_int * 2;
    }

    size_t new_size = array_list->size + 1;

    array_list->data[new_size - 1] = number;
    array_list->size = new_size;
}

int pop(ArrayList *array_list) {
    if(array_list->size == 0) {
        return -1;
    }

    int index = array_list->size - 1;
    int value_stored = get(array_list, index);
    array_list->size = array_list->size - 1;
    return value_stored;
}

void destroy(ArrayList *array_list) {
    free(array_list->data);
    free(array_list);
}

