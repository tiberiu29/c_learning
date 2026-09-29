#include "hashmap.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const float LOAD_FACTOR = 0.75;

void resize(
        HashMap *map,
        hash_function hash_function,
        size_t key_length) {
    size_t old_capacity = map->capacity;
    size_t new_capacity = old_capacity * 2;
    Node** resized_node_array = calloc(new_capacity, sizeof(Node*));

    Node** old_node_array = map->nodes_array;

    // update original map
    map->nodes_array = resized_node_array;
    map->size = 0;
    map->capacity = new_capacity;
          
    for(size_t i = 0; i < old_capacity; i++) {
        Node* current_node = old_node_array[i];
        while(current_node != NULL) {
            put(map, current_node->key, key_length, hash_function, current_node->val);
            // need a temp before moving to next, otherwise I cannot free memory per node
            Node* temp_node = current_node;
            current_node = current_node->next;
            free(temp_node);
        }

    }
    free(old_node_array);
}

Node *initialize_node(void *key, void *val){
    Node *node = malloc(sizeof(Node));

    if(node == NULL) {
        printf("Node cannot be created");
        exit(1);
    }

    node->key = key;
    node->val = val;
    node->next = NULL;

    return node;
}

HashMap *initialize(size_t initial_size) {
    HashMap *map = malloc(sizeof(HashMap));

    if(map == NULL) {
        printf("Cannot initialize HashMap");
        exit(1);
    }

    Node **node_array = 
        calloc(initial_size, sizeof(Node*));

    if(node_array == NULL) {
        printf("Cannot initialize Nodes");
        exit(1);
    }

    map->nodes_array = node_array;
    map->size = 0;
    map->capacity = initial_size;

    return map;
}

void put(
    HashMap *map,
    void *key,
    size_t key_length,
    hash_function hash,
    void *val){

    float load = (double) (map->size + 1) / map->capacity;

    if(load > LOAD_FACTOR) {
        resize(map, hash, key_length);
    }
    
    int bucket_index = hash(key, key_length) % (map->capacity);

    Node *bucket = map->nodes_array[bucket_index];
    if(bucket == NULL) {
        map->nodes_array[bucket_index] = initialize_node(key, val);
        map->size = map->size + 1;
    } else {
        Node *current_node = bucket;
        while(current_node != NULL) {
            if(current_node->key == key) {
                current_node->val = val;
                break;
            }
            if(current_node->next == NULL) {
                current_node->next = initialize_node(key, val);
                map->size = map->size + 1;
            }

            current_node = current_node->next;
        }
    }
}

void *get(
    HashMap *map,
    void *key,
    size_t key_length,
    hash_function hash) {

    int bucket_index = hash(key, key_length) % map->capacity;
    Node *bucket = map->nodes_array[bucket_index];

    if(bucket == NULL) {
        return NULL;
    }

    Node *current = bucket;
    while(current != NULL) {
        if(current->key == key) {
            return current->val;
        }
        current = current->next;
    }

    return NULL;
}

void destroy(HashMap *map){
    for(size_t i = 0; i < map->capacity; i++) {
        Node *current = map->nodes_array[i];

        while(current != NULL) {
            Node *next = current->next;
            free(current);
            current = next;
        }

    }
        free(map->nodes_array);
        free(map);
}


