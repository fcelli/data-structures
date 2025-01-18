#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _linked_list linked_list_t;

linked_list_t* linked_list_create();
void linked_list_destroy(linked_list_t* ll);
size_t linked_list_size(linked_list_t* ll);
bool linked_list_push_front(linked_list_t* ll, void* obj);
bool linked_list_push_back(linked_list_t* ll, void* obj);
void* linked_list_peek_front(linked_list_t* ll);
void* linked_list_peek_back(linked_list_t* ll);
void* linked_list_pop_front(linked_list_t* ll);
void* linked_list_pop_back(linked_list_t* ll);
void* linked_list_lookup(linked_list_t* ll, size_t index);
bool linked_list_insert(linked_list_t* ll, size_t index, void* obj);
void* linked_list_delete(linked_list_t* ll, size_t index);

#endif
