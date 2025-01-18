#include "hashtable.h"
#include <assert.h>

uint64_t simple_hash(const char* key) {
    uint64_t hash = 0;
    while (*key) {
        hash = (hash << 5) + hash + *key++;
    }
    return hash;
}

void print_test_passed(const char* test_name) {
    printf("\t- %s: \033[1;32mPASSED\033[0m\n", test_name);
}

void test_hash_table_create_destroy() {
    hash_table_t* ht = hash_table_create(10, simple_hash);
    assert(ht != NULL);
    hash_table_destroy(ht);
    print_test_passed(__func__);
}

void test_hash_table_insert_lookup() {
    hash_table_t* ht = hash_table_create(10, simple_hash);
    assert(hash_table_insert(ht, "key1", (void*)1) == true);
    assert(hash_table_insert(ht, "key2", "value") == true);
    void* value = hash_table_lookup(ht, "key1");
    assert(value == (void*)1);
    value = hash_table_lookup(ht, "key2");
    assert(strcmp(value, (void*)"value") == 0);
    hash_table_destroy(ht);
    print_test_passed(__func__);
}

void test_hash_table_delete() {
    hash_table_t* ht = hash_table_create(10, simple_hash);
    hash_table_insert(ht, "key", (void*)1);
    assert(hash_table_delete(ht, "key") == (void*)1);
    assert(hash_table_lookup(ht, "key") == NULL);
    hash_table_destroy(ht);
    print_test_passed(__func__);
}

int main(int argc, char** argv) {
    printf("Running tests in: %s\n", argv[0]);
    test_hash_table_create_destroy();
    test_hash_table_insert_lookup();
    test_hash_table_delete();
    return 0;
}
