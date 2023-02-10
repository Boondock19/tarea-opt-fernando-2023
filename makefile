CC = gcc
CFLAGS = -ansi -Wall -pedantic

all: prompt

prompt: prompt.o
	$(CC) $(CFLAGS) -o prompt prompt.o

prompt.o:
	$(CC) $(CFLAGS) -c prompt.c

clean:
	rm *.o prompt