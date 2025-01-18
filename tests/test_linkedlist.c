#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void print_test_passed(const char* test_name) {
    printf("\t- %s: \033[1;32mPASSED\033[0m\n", test_name);
}

void test_linked_list_create_destroy() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    assert(ll != NULL);
    assert(linked_list_size(ll) == 0);
    // Destroy linked list
    linked_list_destroy(ll);
    // Report
    print_test_passed(__func__);
}

void test_linked_list_push_front() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    // Push front element
    assert(linked_list_push_front(ll, (void*)1) == true);
    assert(linked_list_size(ll) == 1);
    // Try pushing front NULL
    assert(linked_list_push_front(ll, NULL) == false);
    assert(linked_list_size(ll) == 1);
    // Destroy linked list and report
    linked_list_destroy(ll);
    print_test_passed(__func__);
}

void test_linked_list_push_back() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    // Push back element
    assert(linked_list_push_back(ll, (int*)1) == true);
    assert(linked_list_size(ll) == 1);
    // Try pushing back NULL
    assert(linked_list_push_back(ll, NULL) == false);
    assert(linked_list_size(ll) == 1);
    // Destroy linked list and report
    linked_list_destroy(ll);
    print_test_passed(__func__);
}

void test_linked_list_peek_front() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    // Peek front on empty linked list
    void* head_obj = linked_list_peek_front(ll);
    assert(head_obj == NULL);
    assert(linked_list_size(ll) == 0);
    // Push front first element and peek front
    linked_list_push_front(ll, (int*)1);
    head_obj = linked_list_peek_front(ll);
    assert(head_obj == (int*)1);
    assert(linked_list_size(ll) == 1);
    // Push front second element and peek front
    linked_list_push_front(ll, "value");
    head_obj = linked_list_peek_front(ll);
    assert(strcmp(head_obj, "value") == 0);
    assert(linked_list_size(ll) == 2);
    // Destroy linked list and report
    linked_list_destroy(ll);
    print_test_passed(__func__);
}

void test_linked_list_peek_back() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    // Peek back on empty linked list
    void* tail_obj = linked_list_peek_back(ll);
    assert(tail_obj == NULL);
    assert(linked_list_size(ll) == 0);
    // Push back first element and peek back
    linked_list_push_back(ll, (int*)1);
    tail_obj = linked_list_peek_back(ll);
    assert(tail_obj == (int*)1);
    assert(linked_list_size(ll) == 1);
    // Puch back second element and peek back
    linked_list_push_back(ll, "value");
    tail_obj = linked_list_peek_back(ll);
    assert(strcmp(tail_obj, "value") == 0);
    assert(linked_list_size(ll) == 2);
    // Destroy linked list and report
    linked_list_destroy(ll);
    print_test_passed(__func__);
}

void test_linked_list_pop_front() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    // Push front two elements
    linked_list_push_front(ll, (int*)1);
    linked_list_push_front(ll, "value");
    // Pop front first time
    void* head_obj = linked_list_pop_front(ll);
    assert(strcmp(head_obj, "value") == 0);
    assert(linked_list_size(ll) == 1);
    // Pop front second time
    head_obj = linked_list_pop_front(ll);
    assert(head_obj == (int*)1);
    assert(linked_list_size(ll) == 0);
    // Pop front third time
    head_obj = linked_list_pop_front(ll);
    assert(head_obj == NULL);
    assert(linked_list_size(ll) == 0);
    // Destroy linked list and report
    linked_list_destroy(ll);
    print_test_passed(__func__);
}

void test_linked_list_pop_back() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    // Push back two elements
    linked_list_push_back(ll, (int*)1);
    linked_list_push_back(ll, "value");
    // Pop back first time
    void* tail_obj = linked_list_pop_back(ll);
    assert(strcmp(tail_obj, "value") == 0);
    assert(linked_list_size(ll) == 1);
    // Pop back second time
    tail_obj = linked_list_pop_back(ll);
    assert(tail_obj == (int*)1);
    assert(linked_list_size(ll) == 0);
    // Pop back third time
    tail_obj = linked_list_pop_back(ll);
    assert(tail_obj == NULL);
    assert(linked_list_size(ll) == 0);
    // Destroy linked list and report
    linked_list_destroy(ll);
    print_test_passed(__func__);
}

void test_linked_list_lookup() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    // Push back nodes
    linked_list_push_back(ll, (int*)1);
    linked_list_push_back(ll, (int*)2);
    linked_list_push_back(ll, (int*)3);
    // Lookup elements
    int* obj = linked_list_lookup(ll, 0);
    assert(obj == (int*)1);
    obj = linked_list_lookup(ll, 1);
    assert(obj == (int*)2);
    obj = linked_list_lookup(ll, 2);
    assert(obj == (int*)3);
    obj = linked_list_lookup(ll, 3);
    assert(obj == NULL);
    // Destroy linked list and report
    linked_list_destroy(ll);
    print_test_passed(__func__);
}

void test_linked_list_insert() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    // Insert at the beginning
    assert(linked_list_insert(ll, 0, (int*)1) == true);
    assert(linked_list_size(ll) == 1);
    assert(linked_list_peek_front(ll) == (int*)1);
    // Insert at the end
    assert(linked_list_insert(ll, 1, (int*)3) == true);
    assert(linked_list_size(ll) == 2);
    assert(linked_list_peek_back(ll) == (int*)3);
    // Insert in the middle
    assert(linked_list_insert(ll, 1, (int*)2) == true);
    assert(linked_list_size(ll) == 3);
    assert(linked_list_lookup(ll, 1) == (int*)2);
    // Insert invalid
    assert(linked_list_insert(ll, 10, (int*)10) == false);
    assert(linked_list_size(ll) == 3);
    // Destroy linked list and report
    linked_list_destroy(ll);
    print_test_passed(__func__);
}

void test_linked_list_delete() {
    // Create linked list
    linked_list_t* ll = linked_list_create();
    // Push back nodes
    linked_list_push_back(ll, (int*)1);
    linked_list_push_back(ll, (int*)2);
    linked_list_push_back(ll, (int*)3);
    linked_list_push_back(ll, (int*)4);
    // Delete invalid
    assert(linked_list_delete(ll, 10) == NULL);
    assert(linked_list_size(ll) == 4);
    // Delete from within
    assert(linked_list_delete(ll, 1) == (int*)2);
    assert(linked_list_size(ll) == 3);
    // Delete from the front
    assert(linked_list_delete(ll, 0) == (int*)1);
    assert(linked_list_size(ll) == 2);
    // Delete from the back
    assert(linked_list_delete(ll, 1) == (int*)4);
    assert(linked_list_size(ll) == 1);
    // Destroy linked list and report
    linked_list_destroy(ll);
    print_test_passed(__func__);
}

int main(int argc, char** argv) {
    printf("Running tests in: %s\n", argv[0]);
    test_linked_list_create_destroy();
    test_linked_list_push_front();
    test_linked_list_push_back();
    test_linked_list_peek_front();
    test_linked_list_peek_back();
    test_linked_list_pop_front();
    test_linked_list_pop_back();
    test_linked_list_lookup();
    test_linked_list_insert();
    test_linked_list_delete();
    return 0;
}
