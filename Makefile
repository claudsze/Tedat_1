CC=gcc
CFLAGS=-Wall -g -pedantic

.PHONY: clean_object clean_exe clean

all: test_reverse

test_reverse: test_reverse.o queue.o
	gcc -o $@ test_reverse.o queue.o

queue.o: queue.c queue.h types.h
	$(CC) $(CFLAGS) -c $< -o $@

test_reverse.o: test_reverse.c queue.h types.h
	$(CC) $(CFLAGS) -c $< -o $@

clean_object:
	rm -f *.o

clean_exe :
	rm -f test_reverse

clean: clean_object clean_exe