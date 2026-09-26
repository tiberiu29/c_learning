.PHONY: test clean

CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -g
INCLUDES= -Isrc -I/workspace/unity

test:
	$(CC) $(CFLAGS) $(INCLUDES) \
		src/hash_util.c \
		src/hashmap.c \
		../unity/unity.c \
		test/test_hashmap.c \
		-o test_hashmap
	./test_hashmap

clean:
	rm -f test_hashmap
