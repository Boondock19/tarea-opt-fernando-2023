CC = cc -c
CFLAGS =
LINKEAR  = cc


all: prompt

# prompt: prompt.o
# 	$(CC) $(CFLAGS) -o prompt prompt.o hashtable.o

# prompt.o: hashtable
# 	$(CC) $(CFLAGS) -c prompt.c

# hashtable: hashtable.o
# 	$(CC) $(CFLAGS) -c hashtable.c hashtable.h

# hashtable.o:
# 	$(CC) $(CFLAGS) -o hashtable hashtable.h

OBJETOS  = hashtable.o prompt.o

prompt: $(OBJETOS)
	$(LINKEAR) $(OBJETOS) -o prompt

prompt.o: prompt.c hashtable.h
	$(CC) prompt.c -o prompt.o

hashtable.o: hashtable.c  hashtable.h user.h
	$(CC) hashtable.c -o hashtable.o

clean:
	rm *.o prompt
	