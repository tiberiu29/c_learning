#include "unity.h"
#include "hashmap.h"

void setUp(void) {
}

void tearDown() {
}


void test_hash_function() {
    char string_1[] = {'a', 'b', 'c', '\0'};
    char string_2[] = {'c', 'b', 'a', '\0'};
    size_t hash_string_1 = hash_string(string_1);
    size_t hash_string_2 = hash_string(string_2);

    TEST_ASSERT_EQUAL_size_t(193485963, hash_string_1);
    TEST_ASSERT_EQUAL_size_t(193488139, hash_string_2);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_hash_function);
    return UNITY_END();
}
