#include "trie.h"
#include "unity.h"

void setUp(void) {
}

void tearDown() {
}

void test_initialize() {
    //given
    Trie *subject = init();

    char word_found_1[] = "wow";
    char word_found_2[] = "woman";
    char word_not_found[] = "woww";

    // when
    add(subject, word_found_1);
    add(subject, word_found_2);

    // then
    TEST_ASSERT_TRUE(contains(subject, word_found_1));
    TEST_ASSERT_TRUE(contains(subject, word_found_2));
    TEST_ASSERT_FALSE(contains(subject, word_not_found));
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_initialize);
    return UNITY_END();
}
