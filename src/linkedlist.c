#include "linkedlist.h"

typedef struct node_t {
    void* object;
    struct node_t* next;
} node_t;

typedef struct _linked_list {
    size_t size;
    struct node_t* head;
    struct node_t* tail;
} linked_list_t;

linked_list_t* linked_list_create() {
    linked_list_t* ll = malloc(sizeof(*ll));
    ll->size = 0;
    ll->head = NULL;
    ll->tail = NULL;
    return ll;
}

void linked_list_destroy(linked_list_t* ll, void (*free_func)(void*)) {
    if (ll == NULL) {
        return;
    }
    node_t* current = ll->head;
    while (current != NULL) {
        if (free_func != NULL && current->object != NULL) {
            free_func(current->object);
        }
        current = current->next;
        free(current);
    }
    free(ll);
}

size_t linked_list_size(linked_list_t* ll) {
    if (ll == NULL) {
        return 0;
    } else {
        return ll->size;
    }
}

bool linked_list_push_front(linked_list_t* ll, void* obj) {
    if (ll == NULL || obj == NULL) {
        return false;
    }

    // Create new node
    node_t* node = malloc(sizeof(*node));
    node->object = obj;
    node->next = ll->head;

    // Update head and tail
    ll->head = node;
    if (ll->tail == NULL) {
        ll->tail = node;
    }
    ll->size += 1;
    return true;
}

bool linked_list_push_back(linked_list_t* ll, void* obj) {
    if (ll == NULL || obj == NULL) {
        return false;
    }

    // Create new node
    node_t* node = malloc(sizeof(*node));
    node->object = obj;
    node->next = NULL;

    // Update head and tail
    if (ll->head == NULL) {
        ll->head = node;
    }
    if (ll->tail != NULL) {
        ll->tail->next = node;
    }
    ll->tail = node;
    ll->size += 1;
    return true;
}

void* linked_list_peek_front(linked_list_t* ll) {
    if (ll == NULL) {
        return NULL;
    }
    if (ll->head == NULL) {
        return NULL;
    } else {
        return ll->head->object;
    }
}

void* linked_list_peek_back(linked_list_t* ll) {
    if (ll == NULL) {
        return NULL;
    }
    if (ll->tail == NULL) {
        return NULL;
    } else {
        return ll->tail->object;
    }
}

void* linked_list_pop_front(linked_list_t* ll) {
    if (ll == NULL) {
        return NULL;
    }
    node_t* node = ll->head;
    if (node == NULL) {
        return NULL;
    }
    if (node->next == NULL) {
        ll->head = NULL;
    } else {
        ll->head = node->next;
    }
    void* obj = node->object;
    free(node);
    ll->size -= 1;
    return obj;
}

void* linked_list_pop_back(linked_list_t* ll) {
    if (ll == NULL) {
        return NULL;
    }
    node_t* node = ll->tail;
    if (node == NULL) {
        return NULL;
    }

    // Handle case when linked list only has one node
    if (ll->size == 1) {
        ll->head = NULL;
        ll->tail = NULL;
        void* obj = node->object;
        free(node);
        ll->size -= 1;
        return obj;
    }

    // Iterate through linked list to find penultimate node
    node_t* tmp = ll->head;
    while (tmp != NULL && tmp->next != node) {
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        return NULL;
    }

    // Set tail to penultimate node
    ll->tail = tmp;
    tmp->next = NULL;

    // Free popped node and return object
    void* obj = node->object;
    free(node);
    ll->size -= 1;
    return obj;
}

static node_t* lookup_node(linked_list_t* ll, size_t index) {
    if (ll == NULL || index >= ll->size || ll->head == NULL) {
        return NULL;
    }
    // Iterate through linked list until desired index
    node_t* node = ll->head;
    size_t n_iter = 0;
    while (n_iter < index) {
        if (node->next == NULL) {
            return NULL;
        }
        node = node->next;
        n_iter += 1;
    }
    return node;
}

void* linked_list_lookup(linked_list_t* ll, size_t index) {
    node_t* node = lookup_node(ll, index);
    if (node == NULL) {
        return NULL;
    }
    return node->object;
}

bool linked_list_insert(linked_list_t* ll, size_t index, void* obj) {
    if (index == 0) {
        // If index is beginning of list, push front
        return linked_list_push_front(ll, obj);

    } else if (index == ll->size) {
        // If index is end of list, push back
        return linked_list_push_back(ll, obj);
    }
    // Look up node before index
    node_t* node = lookup_node(ll, index - 1);
    if (node == NULL) {
        return false;
    }
    node_t* new_node = malloc(sizeof(*new_node));
    new_node->object = obj;
    new_node->next = node->next;
    node->next = new_node;
    ll->size += 1;
    return true;
}

void* linked_list_delete(linked_list_t* ll, size_t index) {
    if (index == 0) {
        // If index is beginning of list, pop front
        return linked_list_pop_front(ll);

    } else if (index == ll->size) {
        // If index is end of list, pop back
        return linked_list_pop_back(ll);
    }
    // Look up node before index
    node_t* prev = lookup_node(ll, index - 1);
    if (prev == NULL) {
        return NULL;
    }
    node_t* node = prev->next;
    prev->next = node->next;
    void* obj = node->object;
    free(node);
    ll->size -= 1;
    return obj;
}
