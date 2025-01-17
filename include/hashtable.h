#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t hash_function(const char* key);
typedef struct _hash_table hash_table;

hash_table* hash_table_create(size_t size, hash_function* hf);
void hash_table_destroy(hash_table* ht);
bool hash_table_insert(hash_table* ht, const char* key, void* obj);
void* hash_table_lookup(hash_table* ht, const char* key);
void* hash_table_delete(hash_table* ht, const char* key);

#endif
