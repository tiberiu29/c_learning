#include "unity.h"
#include "hashmap.h"
#include "hash_util.h"

HashMap *subject;
void setUp(void) {
    subject = initialize();
}

void tearDown() {
    //todo: add destroy
}


void test_map_initialization_with_duplicate_key() {
    // given
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


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_map_initialization_with_duplicate_key);
    return UNITY_END();
}
