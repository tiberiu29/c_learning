#include "string_builder.h"
#include <stddef.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#define INITIAL_CAPACITY 100
#define RESIZE_BUFFER_FACTOR 2

typedef struct StringBuilder{
   char *string;
   size_t size;
   size_t capacity;
}StringBuilder;


char *buffer_initialize(size_t size) {
    char *buffer = malloc(size);

    if(buffer == NULL) {
        printf("Cannot initialize buffer for StringBuilder");
        exit(1);
    }

    return buffer;
}

void resize_buffer(StringBuilder *sb, size_t new_capacity){
    size_t updated_capacity = sb->capacity * new_capacity;
    char *extended_buffer = buffer_initialize(updated_capacity);
    memcpy(extended_buffer, sb->string, sb->size);
    free(sb->string);
    sb->string=extended_buffer;
    sb->capacity=updated_capacity;
}

StringBuilder *sb_initialize(){
    StringBuilder *sb = malloc(sizeof(StringBuilder));
    if(sb == NULL) {
        printf("Cannot initialize StringBuilder");
        exit(1);
    }


    sb->string = buffer_initialize(INITIAL_CAPACITY);
    sb->size = 0;
    sb->capacity = INITIAL_CAPACITY;

    return sb;
}

void sb_destroy(StringBuilder *sb){
    free(sb->string);
    free(sb);
}

void append_char(StringBuilder *sb, char c){
    if(sb->size == sb->capacity) {
        resize_buffer(sb, RESIZE_BUFFER_FACTOR);
    }

    size_t next_empty_index = sb->size;
    sb->string[next_empty_index] = c;
    sb->size++;
}

void append_int(StringBuilder *sb, int n){
    size_t buffer_size = sizeof(n) * 8;
    char buffer[buffer_size];

    int written_chars = snprintf(buffer, buffer_size, "%d", n);

    for(int i = 0; i < written_chars; i++) {
        append_char(sb, buffer[i]);
    }
}

char *to_string(StringBuilder *sb){
    if(sb->size == 0) {
        return "";
    }

    char *string = malloc(sb->size + 1);
    memcpy(string, sb->string, sb->size);
    string[sb->size] = '\0';
    return string;
}

void sb_clear(StringBuilder *sb) {
    sb->size = 0;
}

size_t get_size(StringBuilder *sb) {
    return sb->size;
}

