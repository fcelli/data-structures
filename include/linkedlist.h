/**
 * @file linkedlist.h
 * @brief Header file for a generic linked list implementation in C.
 *
 * This file provides the interface for a linked list data structure,
 * supporting basic operations such as insertion, deletion, access,
 * and size retrieval. The linked list stores generic void pointers,
 * allowing it to handle different data types.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>

/** @brief Opaque structure representing a linked list. */
typedef struct _linked_list linked_list_t;

/**
 * @brief Creates a new linked list.
 *
 * Allocates and initializes a new linked list structure.
 *
 * @return A pointer to the created linked list.
 */
linked_list_t* linked_list_create();

/**
 * @brief Destroys the linked list and optionally frees the objects stored in
 * it.
 *
 * This function iterates through the linked list, freeing each node. If a
 * function pointer is provided, it is called on each object stored in the list
 * to free any additional resources associated with the objects.
 *
 * @param ll Pointer to the linked list to destroy.
 * @param free_func Function pointer to a function that frees the objects in the
 * list. If NULL, the objects are not freed.
 */
void linked_list_destroy(linked_list_t* ll, void (*free_func)(void*));

/**
 * @brief Gets the number of elements in the linked list.
 *
 * @param ll Pointer to the linked list.
 * @return The number of elements in the list, or 0 if the list is NULL.
 */
size_t linked_list_size(linked_list_t* ll);

/**
 * @brief Adds an object to the front of the linked list.
 *
 * @param ll Pointer to the linked list.
 * @param obj Pointer to the object to add.
 * @return True on success, false on failure.
 */
bool linked_list_push_front(linked_list_t* ll, void* obj);

/**
 * @brief Adds an object to the back of the linked list.
 *
 * @param ll Pointer to the linked list.
 * @param obj Pointer to the object to add.
 * @return True on success, false on failure.
 */
bool linked_list_push_back(linked_list_t* ll, void* obj);

/**
 * @brief Retrieves the object at the front of the linked list without removing
 * it.
 *
 * @param ll Pointer to the linked list.
 * @return A pointer to the object at the front, or NULL if the list is empty or
 * NULL.
 */
void* linked_list_peek_front(linked_list_t* ll);

/**
 * @brief Retrieves the object at the back of the linked list without removing
 * it.
 *
 * @param ll Pointer to the linked list.
 * @return A pointer to the object at the back, or NULL if the list is empty or
 * NULL.
 */
void* linked_list_peek_back(linked_list_t* ll);

/**
 * @brief Removes and retrieves the object at the front of the linked list.
 *
 * @param ll Pointer to the linked list.
 * @return A pointer to the removed object, or NULL if the list is empty or
 * NULL.
 */
void* linked_list_pop_front(linked_list_t* ll);

/**
 * @brief Removes and retrieves the object at the back of the linked list.
 *
 * @param ll Pointer to the linked list.
 * @return A pointer to the removed object, or NULL if the list is empty or
 * NULL.
 */
void* linked_list_pop_back(linked_list_t* ll);

/**
 * @brief Retrieves the object at a specific index in the linked list, measured
 * from the head of the list. The head's index is 0.
 *
 * @param ll Pointer to the linked list.
 * @param index The index of the desired object (0-based).
 * @return A pointer to the object at the specified index, or NULL if the index
 * is out of range or the list is NULL.
 */
void* linked_list_lookup(linked_list_t* ll, size_t index);

/**
 * @brief Inserts an object at a specific index in the linked list.
 *
 * The index must be in the range [0, size], where 0 adds to the front, and size
 * adds to the back.
 *
 * @param ll Pointer to the linked list.
 * @param index The index where the object should be inserted (0-based).
 * @param obj Pointer to the object to insert.
 * @return True on success, false if the index is invalid.
 */
bool linked_list_insert(linked_list_t* ll, size_t index, void* obj);

/**
 * @brief Deletes and retrieves the object at a specific index in the linked
 * list.
 *
 * The index must be in the range [0, size-1].
 *
 * @param ll Pointer to the linked list.
 * @param index The index of the object to delete (0-based).
 * @return A pointer to the removed object, or NULL if the index is out of range
 * or the list is NULL.
 */
void* linked_list_delete(linked_list_t* ll, size_t index);

#endif // LINKEDLIST_H
