#include "hashmap.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

const size_t INITIAL_CAPACITY = 10;

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

HashMap *initialize() {
    HashMap *map = malloc(sizeof(HashMap));

    if(map == NULL) {
        printf("Cannot initialize HashMap");
        exit(1);
    }

    Node **node_array = 
        calloc(INITIAL_CAPACITY, sizeof(Node*));

    if(node_array == NULL) {
        printf("Cannot initialize Nodes");
        exit(1);
    }

    map->nodes_array = node_array;
    map->array_size = 0;
    map->array_capacity = INITIAL_CAPACITY;

    return map;
}


void put(
    HashMap *map,
    void *key,
    size_t key_length,
    hash_function hash,
    void *val){

    int bucket_index = hash(key, key_length) % (map->array_capacity - 1);

    Node *bucket = map->nodes_array[bucket_index];
    if(bucket == NULL) {
        map->nodes_array[bucket_index] = initialize_node(key, val);
        return;
    } else {
        Node *current_node = bucket;
        while(current_node != NULL) {
            if(current_node->key == key) {
                current_node->val = val;
                break;
            }
            if(current_node->next == NULL) {
                current_node->next = initialize_node(key, val);
            }
        }
    }





}
















