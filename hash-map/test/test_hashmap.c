#include "unity.h"
#include "hashmap.h"
#include "hash_util.h"

HashMap *subject;
void setUp(void) {
}

void tearDown() {
    destroy(subject);
}


void test_insert_string_keys() {
    // given
    subject = initialize(10);

    char key_1[] = {'A', 'B', 'C'};
    int *val_1 = malloc(sizeof(int));
    *val_1 = 23;

    char key_2[] = {'A', 'B', 'C', 'D'};
    int *val_2 = malloc(sizeof(int));
    *val_2 = 99;

    // when
    put(subject, key_1, sizeof(key_1), &djb2_hash, val_1);
    put(subject, key_2, sizeof(key_2), &djb2_hash, val_2);

    // then
    int *found_val_1 = get(subject, key_1, sizeof(key_1), &djb2_hash);
    int *found_val_2 = get(subject, key_2, sizeof(key_2), &djb2_hash);

    TEST_ASSERT_INT_WITHIN(0, *val_1, *found_val_1);
    TEST_ASSERT_INT_WITHIN(0, *val_2, *found_val_2);
}

void test_map_initialization_with_duplicate_key() {
    // given
    subject = initialize(10);
    int *key = malloc(sizeof(int));
    key[0] = 29;

    int *val_1 = malloc(sizeof(int));
    val_1[0] = 12;
    int *val_2 = malloc(sizeof(int));
    val_2[0] = 15;

    // when
    put(subject, key, sizeof(int), &joaat_hash, val_1);
    put(subject, key, sizeof(int), &joaat_hash, val_2 );

    // then
    int *found_val = get(subject, key, sizeof(int), &joaat_hash);
    TEST_ASSERT_INT_WITHIN(0, *val_2, *found_val);
}

void test_resize() {
    // given
    subject = initialize(2);
    int *key_1 = malloc(sizeof(int));
    key_1[0] = 29;
    int *val_1 = malloc(sizeof(int));
    val_1[0] = 12;

    int *key_2 = malloc(sizeof(int));
    key_2[0] = 13;
    int *val_2 = malloc(sizeof(int));
    val_2[0] = 9999;

    int *key_3 = malloc(sizeof(int));
    key_3[0] = 39;
    int *val_3 = malloc(sizeof(int));
    val_3[0] = 8879;

    // when
    put(subject, key_1, sizeof(int), &joaat_hash, val_1);
    put(subject, key_2, sizeof(int), &joaat_hash, val_2);
    put(subject, key_3, sizeof(int), &joaat_hash, val_3);

    //then
    int *found_val_1 = get(subject, key_1, sizeof(int), &joaat_hash);
    TEST_ASSERT_INT_WITHIN(0, *val_1, *found_val_1);
    int *found_val_2 = get(subject, key_2, sizeof(int), &joaat_hash);
    TEST_ASSERT_INT_WITHIN(0, *val_2, *found_val_2);
    int *found_val_3 = get(subject, key_3, sizeof(int), &joaat_hash);
    TEST_ASSERT_INT_WITHIN(0, *val_3, *found_val_3);

    TEST_ASSERT_INT_WITHIN(0, 4, subject->capacity);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_insert_string_keys);
    RUN_TEST(test_map_initialization_with_duplicate_key);
    RUN_TEST(test_resize);
    return UNITY_END();
}
