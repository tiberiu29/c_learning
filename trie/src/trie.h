#ifndef TRIE_H
#define TRIE_H
#include <stdbool.h>
#include <stddef.h>

typedef struct Node{
   struct Node *children[26];
   bool is_word;
}Node;

typedef struct Trie{
    Node *root;
}Trie;

Trie *init();
void add(Trie *trie, char *word);
bool contains(Trie *trie, char *word);
#endif // !
