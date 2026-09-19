#include "unity.h"
#include "arraylist.h"

ArrayList *subject;

void setUp(void) {
}

void tearDown() {
}


void test_add_does_not_underflow_float(void) {
    // given
    subject = initialize(5, sizeof(float));
    float expected_array[] = {999.3, 0.2, 1.1, 2.99, 3.332};
    float element_1 = 0.2;
    float element_2 = 1.1;
    float element_3 = 2.99;
    float element_4 = 3.332;
    float element_to_add = 999.3;

    // when
    push(subject, &element_1);
    push(subject, &element_2);
    push(subject, &element_3);
    push(subject, &element_4);
    add(subject, 0, &element_to_add);

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, subject->data, 5);
    destroy(subject);
}

void test_remove_does_not_underflow_float(void) {
    // given
    subject = initialize(5, sizeof(float));
    float expected_array[] = {1.1, 2.99};
    float element_1 = 0.2;
    float element_2 = 1.1;
    float element_3 = 2.99;

    // when
    push(subject, &element_1);
    push(subject, &element_2);
    push(subject, &element_3);
    remove_at(subject, 0);

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, subject->data, 2);
    destroy(subject);
}

void test_resize_works_properly_float(void) {
    // given
    subject = initialize(5, sizeof(float));
    float expected_array[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    size_t expected_size = 6;
    size_t expected_capacity = 10;
    float element_1 = 1.1;
    float element_2 = 2.2;
    float element_3 = 3.3;
    float element_4 = 4.4;
    float element_5 = 5.5;
    float element_6 = 6.6;

    // when
    push(subject, &element_1);
    push(subject, &element_2);
    push(subject, &element_3);
    push(subject, &element_4);
    push(subject, &element_5);
    push(subject, &element_6);

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, subject->data, expected_size);
    TEST_ASSERT_EQUAL_UINT(expected_size, subject->size);
    TEST_ASSERT_EQUAL_UINT(expected_capacity, subject->capacity);
    destroy(subject);
}

void test_add_does_not_underflow_int(void) {
    // given
    subject = initialize(5, sizeof(int));
    int expected_array[] = {999, 0, 1, 2, 3};
    int element_1 = 0;
    int element_2 = 1;
    int element_3 = 2;
    int element_4 = 3;
    int element_to_add = 999;

    // when
    push(subject, &element_1);
    push(subject, &element_2);
    push(subject, &element_3);
    push(subject, &element_4);
    add(subject, 0, &element_to_add);

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, subject->data, 5);
    destroy(subject);
}

void test_remove_does_not_underflow_int(void) {
    // given
    subject = initialize(5, sizeof(int));
    int expected_array[] = {2, 3};
    int element_1 = 999;
    int element_2 = 2;
    int element_3 = 3;
    // when
    push(subject, &element_1);
    push(subject, &element_2);
    push(subject, &element_3);
    remove_at(subject, 0);

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, subject->data, 2);
    destroy(subject);
}

void test_resize_works_properly_int(void) {
    // given
    subject = initialize(5, sizeof(int));
    int expected_array[] = {1, 2, 3, 4, 5, 6};
    size_t expected_size = 6;
    size_t expected_capacity = 10;

    // when
    for(size_t i = 1; i <= expected_size; i++) {
        push(subject, &i);
    }

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, subject->data, expected_size);
    TEST_ASSERT_EQUAL_UINT(expected_size, subject->size);
    TEST_ASSERT_EQUAL_UINT(expected_capacity, subject->capacity);
    destroy(subject);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_does_not_underflow_float);
    RUN_TEST(test_remove_does_not_underflow_float);
    RUN_TEST(test_resize_works_properly_float);
    RUN_TEST(test_add_does_not_underflow_int);
    RUN_TEST(test_remove_does_not_underflow_int);
    RUN_TEST(test_resize_works_properly_int);
    return UNITY_END();
}
