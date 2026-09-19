#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *get_element_address(ArrayList *array_list, size_t offset){
    unsigned char * byte_pointer = ((unsigned char *) array_list -> data);
    return (void *) (byte_pointer + offset);
}

void extend_capacity(ArrayList *array_list) {
    size_t current_capacity_int = array_list->capacity;
    size_t current_capacity_bytes = 
        current_capacity_int * array_list->element_size_bytes;

    void *realloc_data = 
        realloc(array_list->data, current_capacity_bytes * 2 );

    if(realloc_data == NULL) {
        printf("Could not reallocate array for size increase");
        exit(1);
    }

    array_list->data = realloc_data;
    array_list->capacity = current_capacity_int * 2;
}

ArrayList *initialize(size_t initial_capacity, size_t element_size_bytes) {
    int *data = malloc(initial_capacity * element_size_bytes);
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
    array_list->element_size_bytes = element_size_bytes;

    return array_list;
    
}

void *get(ArrayList *array_list, size_t index) {
    if(index >=  array_list->size) {
        printf("Index out of bounds");
        exit(1);
    }

    size_t offset = index * array_list->element_size_bytes;
    return get_element_address(array_list, offset);
}

void push(ArrayList *array_list, void *element) {
    add(array_list, array_list->size, element);
}

void *pop(ArrayList *array_list) {
    size_t index = array_list->size - 1;
    return remove_at(array_list, index);
}

void add(ArrayList *array_list, size_t index, void *element) {
    // we can also append at the end of array
    // similar to a push, hence it is OK if index == size
    if(index > array_list->size){
        printf("Index out of bounds");
        exit(1);
    }

    if(array_list->capacity == array_list->size) {
        extend_capacity(array_list);
    }

    size_t offset = array_list->element_size_bytes * index;

    void *source_address = 
        get_element_address(array_list, offset);
    void *destination_address =
        get_element_address(array_list, offset + array_list->element_size_bytes);
    size_t bytes_to_move =
        (array_list->size - index) * array_list->element_size_bytes;

    memmove(destination_address, source_address, bytes_to_move);
    memcpy(source_address, element, array_list->element_size_bytes);
    array_list->size = array_list->size + 1;
}

//TODO: add shrinking logic if size < 1/2 capacity
void *remove_at(ArrayList *array_list, size_t index) {
    if(index >= array_list->size) {
        printf("Index out of bounds");
        exit(1);
    }

    size_t offset = array_list->element_size_bytes * index;
    void *value_stored = get(array_list, index);
    void *value_new_address = malloc(array_list->element_size_bytes);
    memcpy(value_new_address, value_stored, array_list->element_size_bytes);

    void *start_index = 
        get_element_address(array_list, offset + array_list->element_size_bytes);
    void *destination_index = 
        get_element_address(array_list, offset);
    size_t bytes_to_move = 
        (array_list->size - (index + 1)) * array_list->element_size_bytes;
    
    memmove(destination_index, start_index, bytes_to_move);
    
    array_list->size = array_list->size - 1;
    // I know this will leak memory
    // Because the caller will probably never free this element
    // But for now it's a fun exercise
    return value_new_address;
}

void destroy(ArrayList *array_list) {
    free(array_list->data);
    free(array_list);
}

