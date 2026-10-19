#include "unity.h"
#include "string_builder.h"
#include <string.h>

StringBuilder *subject;

void setUp(void) {
    subject = sb_initialize();
}

void tearDown() {
    sb_destroy(subject);
}

void test_subject_can_append_max_int(void) {
    // given
    append_int(subject, INT_MAX);

    // when
    char *result = to_string(subject);

    // then
    TEST_ASSERT_EQUAL_STRING("2147483647", result);
}

void test_subject_can_append_min_int(void) {
    // given
    append_int(subject, INT_MIN);

    // when
    char *result = to_string(subject);

    // then
    TEST_ASSERT_EQUAL_STRING("-2147483648", result);
}


void test_subject_can_remove_at_index(void) {
    // given
    append_char(subject, 'a');
    append_char(subject, 'b');
    append_char(subject, 'c');

    // when
    remove_at(subject, 0);
    char *result = to_string(subject);

    // then
    TEST_ASSERT_EQUAL_STRING("bc", result);
    TEST_ASSERT_EQUAL_size_t(2, strlen(result));
}

void test_subject_cannot_remove_outer_bounds(void) {
    // given
    append_char(subject, 'a');
    append_char(subject, 'b');
    append_char(subject, 'c');

    // when
    remove_at(subject, 10);
    char *result = to_string(subject);

    // then
    TEST_ASSERT_EQUAL_STRING("abc", result);
    TEST_ASSERT_EQUAL_size_t(3, strlen(result));
}
void test_subject_can_remove_last(void) {
    // given
    append_char(subject, 'c');
    append_char(subject, 'd');

    // when
    remove_last(subject);
    char *result = to_string(subject);

    // then
    TEST_ASSERT_EQUAL_STRING("c", result);
    TEST_ASSERT_EQUAL_size_t(1, strlen(result));
}

void test_subject_can_append_within_bounds(void) {
    // given
    append_char(subject, 'c');
    append_char(subject, 'd');
    append_int(subject, 1234);

    // when
    char *result = to_string(subject);

    // then
    TEST_ASSERT_EQUAL_STRING("cd1234", result);
    TEST_ASSERT_EQUAL_size_t(6, strlen(result));
}

void test_subject_can_append_outside_bounds(void) {
    // given
    for(int i = 0; i < 101; i++) {
        append_int(subject, i);
    }

    // when
    char *result = to_string(subject);

    // then
    TEST_ASSERT_EQUAL_size_t(193, strlen(result));
}

void test_subject_can_clear(void) {
    // given
    for(int i = 0; i < 101; i++) {
        append_int(subject, i);
    }

    // when
    sb_clear(subject);
    char *result = to_string(subject);

    // then
    TEST_ASSERT_EQUAL_STRING("", result);
    TEST_ASSERT_EQUAL_size_t(0, strlen(result));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_subject_can_remove_at_index);
    RUN_TEST(test_subject_cannot_remove_outer_bounds);
    RUN_TEST(test_subject_can_remove_last);
    RUN_TEST(test_subject_can_clear);
    RUN_TEST(test_subject_can_append_max_int);
    RUN_TEST(test_subject_can_append_min_int);
    RUN_TEST(test_subject_can_append_within_bounds);
    RUN_TEST(test_subject_can_append_outside_bounds);
    return UNITY_END();
}
