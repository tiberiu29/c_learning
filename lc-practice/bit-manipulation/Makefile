.PHONY: test clean

CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -g
INCLUDES= -Isrc -I/workspace/unity

test:
	$(CC) $(CFLAGS) $(INCLUDES) \
		src/*.c \
		../../unity/unity.c \
		test/test_bit_manipulation.c \
		-o test_bit_manipulation
	./test_bit_manipulation

clean:
	rm -f test_bit_manipulation
