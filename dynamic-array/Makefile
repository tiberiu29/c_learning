.PHONY: test clean

CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -g
INCLUDES= -Isrc -Iunity

test:
	$(CC) $(CFLAGS) $(INCLUDES) \
		src/arraylist.c \
		unity/unity.c \
		test/test_arraylist.c \
		-o test_arraylist
	./test_arraylist

clean:
	rm -f test_arraylist
