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


void test_map_initialization() {
    int *key = malloc(sizeof(int));
    key[0] = 29;
    int *val = malloc(sizeof(int));
    val[0] = 12;

    put(subject, key, sizeof(int), &joaat_hash, val);

    Node node = *subject->nodes_array[0];

    TEST_ASSERT_INT_WITHIN(0, 29, *((int*)node.key));
    TEST_ASSERT_INT_WITHIN(0, 12, *((int*)node.val));
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_map_initialization);
    return UNITY_END();
}
