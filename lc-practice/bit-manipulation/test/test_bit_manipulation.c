#include "number_complement.h"
#include "reverse_bits.h"
#include "hamming_weight.h"
#include "power_of_two.h"
#include "alternating_bits.h"
#include "unity.h"

void setUp(void) {
}

void tearDown() {
}

void test_alternating_bits(){
    TEST_ASSERT_INT_WITHIN(0, true, hasAlternatingBits(5));
    TEST_ASSERT_INT_WITHIN(0, false, hasAlternatingBits(11));
}

void test_power_of_two(){
    TEST_ASSERT_INT_WITHIN(0, true, isPowerOfTwo(1));
    TEST_ASSERT_INT_WITHIN(0, true, isPowerOfTwo(16));
    TEST_ASSERT_INT_WITHIN(0, false, isPowerOfTwo(3));
    TEST_ASSERT_INT_WITHIN(0, false, isPowerOfTwo(0));
}
void test_hamming_weight() {
    TEST_ASSERT_INT_WITHIN(0, 3, hammingWeight(11));
    TEST_ASSERT_INT_WITHIN(0, 1, hammingWeight(128));
    TEST_ASSERT_INT_WITHIN(0, 30, hammingWeight(2147483645));
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
    RUN_TEST(test_hamming_weight);
    RUN_TEST(test_power_of_two);
    RUN_TEST(test_alternating_bits);
    return UNITY_END();
}
