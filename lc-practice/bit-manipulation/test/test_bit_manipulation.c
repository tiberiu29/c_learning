#include "number_complement.h"
#include "unity.h"

void setUp(void) {
}

void tearDown() {
}

void test_num_complement() {
    int input_num = 5;
    int expected_complement = 2;

    int result = findComplement(input_num);

    TEST_ASSERT_INT_WITHIN(0, expected_complement, result);
}

void test_num_complement_not_supporting_numbers_less_than_1() {
    int input_num = 0;

    int result = findComplement(input_num);

    TEST_ASSERT_INT_WITHIN(0, -1, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_num_complement);
    RUN_TEST(test_num_complement_not_supporting_numbers_less_than_1);
    return UNITY_END();
}
