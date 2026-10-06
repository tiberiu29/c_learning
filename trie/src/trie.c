#include "trie.h"
#include <stdlib.h>
#include <stdio.h>

size_t calculate_index(char c) {
   return c - 'a';
}

Trie *init() {
    Node *root = calloc(1, sizeof(Node));

    if(root == NULL) {
        printf("Could not initialize root node");
    }

    Trie *trie = malloc(sizeof(Trie));
    trie->root = root;
    
    return trie;
}
void add(Trie *trie, char *word) {
    int current_index = 0;
    Node *current_node = trie->root;
    while(word[current_index] != '\0') {
        size_t insert_index = calculate_index(word[current_index]);
        if(current_node->children[insert_index] == NULL) {
            Node *new_node = calloc(1, sizeof(Node));
            current_node->children[insert_index] = new_node;
            current_node = new_node;
        } else {
            current_node = current_node->children[insert_index];
        }     
        current_index++;
    }
    current_node->is_word = true;
}

bool contains(Trie *trie, char *word) {
    int current_index = 0;
    Node *current_node = trie->root;

    while(word[current_index] != '\0') {
        size_t node_index = calculate_index(word[current_index]);
        current_node = current_node->children[node_index];

        if(current_node == NULL) {
            return false;
        }

        current_index++;
    }

    return current_node->is_word;
}
