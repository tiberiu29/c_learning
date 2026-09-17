#include "unity.h"
#include "arraylist.h"

ArrayList *subject;

void setUp(void) {
    subject = initialize(5);
}

void tearDown() {
    destroy(subject);
}

void test_add_does_not_underflow(void) {
    // given
    int expected_array[] = {999, 0, 1, 2, 3};

    // when
    push(subject, 0);
    push(subject, 1);
    push(subject, 2);
    push(subject, 3);
    add(subject, 0, 999);

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, subject->data, 5);
}

void test_remove_does_not_underflow(void) {
    // given
    int expected_array[] = {2, 3};

    // when
    push(subject, 999);
    push(subject, 2);
    push(subject, 3);
    remove_at(subject, 0);

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, subject->data, 2);
}

void test_resize_works_properly(void) {
    // given
    int expected_array[] = {1, 2, 3, 4, 5, 6};
    int expected_size = 6;
    int expected_capacity = 10;

    // when
    for(int i = 1; i <= expected_size; i++) {
        push(subject, i);
    }

    // then
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, subject->data, 6);
    TEST_ASSERT_EQUAL_INT(expected_capacity, subject->capacity);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_does_not_underflow);
    RUN_TEST(test_remove_does_not_underflow);
    RUN_TEST(test_resize_works_properly);
    return UNITY_END();
}
