#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void extend_capacity(ArrayList *array_list) {
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

int get(ArrayList *array_list, size_t index) {
    if(index >=  array_list->size) {
        printf("Index out of bounds");
        exit(1);
    }

    return array_list->data[index];
}

void push(ArrayList *array_list, int number) {
    add(array_list, array_list->size,  number);
}

int pop(ArrayList *array_list) {
    int index = array_list->size - 1;
    return remove_at(array_list, index);
}

void add(ArrayList *array_list, size_t index, int value) {
    // we can also append at the end of array
    // similar to a push, hence it is OK if index == size
    if(index > array_list->size){
        printf("Index out of bounds");
        exit(1);
    }

    if(array_list->capacity == array_list->size) {
        extend_capacity(array_list);
    }

    void * start_index = &array_list->data[index];
    void * destination_index = &array_list->data[index + 1];
    size_t bytes_to_move = (array_list->size - index) * sizeof(int);

    memmove(destination_index, start_index, bytes_to_move);
    
    array_list->data[index] = value;
    array_list->size = array_list->size + 1;
}

int remove_at(ArrayList *array_list, size_t index) {
    if(index >= array_list->size) {
        printf("Index out of bounds");
        exit(1);
    }

    int value_stored = get(array_list, index);

    void * start_index = &array_list->data[index + 1] ;
    void * destination_index = &array_list->data[index];
    size_t bytes_to_move = (array_list->size - (index + 1)) * sizeof(int);
    
    memmove(destination_index, start_index, bytes_to_move);
    
    array_list->size = array_list->size - 1;
    return value_stored;
}

void destroy(ArrayList *array_list) {
    free(array_list->data);
    free(array_list);
}

