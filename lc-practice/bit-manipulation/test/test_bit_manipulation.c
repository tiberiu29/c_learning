#include "number_complement.h"
#include "reverse_bits.h"
#include "unity.h"

void setUp(void) {
}

void tearDown() {
}

void test_num_complement() {
    TEST_ASSERT_INT_WITHIN(0, 2, findComplement(5));
    TEST_ASSERT_INT_WITHIN(0, -1, findComplement(0));
}

void test_reverse_bits() {
    TEST_ASSERT_INT_WITHIN(0, 964176192, reverseBits(43261596));
    TEST_ASSERT_INT_WITHIN(0, 1073741822, reverseBits(2147483644));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_num_complement);
    RUN_TEST(test_reverse_bits);
    return UNITY_END();
}
