CC = gcc
CFLAGS = -g -Wall

HDR = types.h slist.h
SRC = slist.c
MAIN = test_slist.c
TARGET = test_slist

all: $(TARGET)

test_slist: $(HDR) $(MAIN) $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN) $(SRC)

clean:
	rm -f $(TARGET)