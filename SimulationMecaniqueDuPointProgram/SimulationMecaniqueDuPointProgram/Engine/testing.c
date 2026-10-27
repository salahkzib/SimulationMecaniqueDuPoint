#include <stdio.h>
#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Node structure for chaining collisions
typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

// Hash table structure
typedef struct {
    Node *buckets[TABLE_SIZE];
} HashTable;

// Simple hash function (djb2 or simple sum)
unsigned int hash(const char *key) {
    unsigned int hash_val = 0;
    while (*key) {
        hash_val = (hash_val * 31) + *key++;
    }
    return hash_val % TABLE_SIZE;
}

// Create and initialize hash table
HashTable* create_table() {
    HashTable *table = malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

// Insert or update a key-value pair
void ht_insert(HashTable *table, const char *key, const char *value) {
    unsigned int idx = hash(key);
    Node *curr = table->buckets[idx];

    // Check if key already exists, update if found
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            free(curr->value);
            curr->value = strdup(value);
            return;
        }
        curr = curr->next;
    }

    // Otherwise, create a new node and insert at the beginning of the bucket list
    Node *new_node = malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = table->buckets[idx];
    table->buckets[idx] = new_node;
}

// Search for a value by key
const char* ht_search(HashTable *table, const char *key) {
    unsigned int idx = hash(key);
    Node *curr = table->buckets[idx];

    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return NULL; // Not found
}

// Example usage
int main() {
    HashTable *my_map = create_table();

    ht_insert(my_map, "username", "alice123");
    ht_insert(my_map, "email", "alice@example.com");

    printf("username: %s\n", ht_search(my_map, "username"));
    printf("email: %s\n", ht_search(my_map, "email"));

    return 0;
}
