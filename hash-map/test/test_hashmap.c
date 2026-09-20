
#include "unity.h"
#include "hashmap.h"

void setUp(void) {
}

void tearDown() {
}


void test_do_nothing() {
    TEST_ASSERT_INT_WITHIN(0, 1, do_nothing());
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_do_nothing);
    return UNITY_END();
}
