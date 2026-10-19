.PHONY: test clean

CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -g
INCLUDES= -Isrc -I/workspace/unity

test:
	$(CC) $(CFLAGS) $(INCLUDES) \
		src/string_builder.c \
		../unity/unity.c \
		test/test_string_builder.c \
		-o test_string_builder
	./test_string_builder

clean:
	rm -f test_string_builder
