#include "hashtable.h"

typedef struct entry_t {
    char* key;
    void* object;
    struct entry_t* next;
} entry_t;

typedef struct _hash_table {
    size_t size;
    hash_function* hash;
    entry_t** elements;
} hash_table_t;

static size_t hash_table_index(hash_table_t* ht, const char* key) {
    size_t index = ht->hash(key) % ht->size;
    return index;
}

hash_table_t* hash_table_create(size_t size, hash_function* hf) {
    hash_table_t* ht = malloc(sizeof(*ht));
    ht->size = size;
    ht->hash = hf;
    ht->elements = calloc(sizeof(entry_t*), size);
    return ht;
}

void hash_table_destroy(hash_table_t* ht) {
    free(ht->elements);
    free(ht);
}

bool hash_table_insert(hash_table_t* ht, const char* key, void* obj) {
    if (key == NULL || obj == NULL) {
        return false;
    }

    // If the key already exists, do not overwrite
    if (hash_table_lookup(ht, key) != NULL) {
        return false;
    }

    size_t index = hash_table_index(ht, key);

    // Create a new entry
    entry_t* e = malloc(sizeof(*e));
    e->key = malloc(strlen(key) + 1);
    strcpy(e->key, key);
    e->object = obj;
    e->next = ht->elements[index];

    // Insert entry in hash table
    ht->elements[index] = e;

    return true;
}

void* hash_table_lookup(hash_table_t* ht, const char* key) {
    if (ht == NULL || key == NULL) {
        return NULL;
    }

    size_t index = hash_table_index(ht, key);
    entry_t* e = ht->elements[index];

    while (e != NULL && strcmp(e->key, key) != 0) {
        e = e->next;
    }

    if (e == NULL) {
        return NULL;
    }

    return e->object;
}

void* hash_table_delete(hash_table_t* ht, const char* key) {
    if (ht == NULL || key == NULL) {
        return NULL;
    }

    size_t index = hash_table_index(ht, key);
    entry_t* e = ht->elements[index];
    entry_t* prev = NULL;

    // Search the entry to be deleted
    while (e != NULL && strcmp(e->key, key) != 0) {
        prev = e;
        e = e->next;
    }

    // The entry is not present, return NULL
    if (e == NULL) {
        return NULL;
    }

    if (prev == NULL) {
        // Delete from the head of the list
        ht->elements[index] = e->next;
    } else {
        // Delete from within the list
        prev->next = e->next;
    }

    void* obj = e->object;
    free(e);
    return obj;
}
