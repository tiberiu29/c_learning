.PHONY: test clean

CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -g
INCLUDES= -Isrc -I/workspace/unity

test:
	$(CC) $(CFLAGS) $(INCLUDES) \
		src/trie.c \
		../unity/unity.c \
		test/test_trie.c \
		-o test_trie
	./test_trie

clean:
	rm -f test_trie
