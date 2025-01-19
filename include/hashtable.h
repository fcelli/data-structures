/**
 * @file hashtable.h
 * @brief Header file for a generic hash table implementation in C.
 *
 * This hash table allows the insertion, lookup, and deletion of key-value
 * pairs, with string keys and generic object values (`void*`). It uses separate
 * chaining for collision resolution.
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * @typedef hash_function
 * @brief Defines a hash function that maps a string key to a uint64_t value.
 *
 * @param key The key to be hashed.
 * @return The hashed value as a uint64_t.
 */
typedef uint64_t hash_function(const char* key);

/**
 * @struct _hash_table
 * @brief Opaque structure representing a hash table.
 */
typedef struct _hash_table hash_table_t;

/**
 * @brief Creates a new hash table.
 *
 * @param size The number of buckets in the hash table.
 * @param hf A pointer to a hash function for mapping keys.
 * @return A pointer to the newly created hash table.
 */
hash_table_t* hash_table_create(size_t size, hash_function* hf);

/**
 * @brief Destroys the hash table and frees all associated memory. Objects
 * stored in the hash table are not freed by this operation.
 *
 * @param ht The hash table to destroy.
 */
void hash_table_destroy(hash_table_t* ht);

/**
 * @brief Inserts a key-value pair into the hash table.
 *
 * @param ht The hash table.
 * @param key The string key for the object.
 * @param obj A pointer to the object to be stored.
 * @return `true` if the insertion is successful, `false` otherwise.
 */
bool hash_table_insert(hash_table_t* ht, const char* key, void* obj);

/**
 * @brief Looks up an object in the hash table by its key.
 *
 * @param ht The hash table.
 * @param key The string key of the object to look up.
 * @return A pointer to the object if found, `NULL` otherwise.
 */
void* hash_table_lookup(hash_table_t* ht, const char* key);

/**
 * @brief Deletes an object from the hash table by its key.
 *
 * @param ht The hash table.
 * @param key The string key of the object to delete.
 * @return A pointer to the deleted object, or `NULL` if the key is not found.
 */
void* hash_table_delete(hash_table_t* ht, const char* key);

#endif // HASHTABLE_H
