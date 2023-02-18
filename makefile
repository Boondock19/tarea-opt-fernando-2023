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

OBJETOS  = linkedList.o hashtable.o prompt.o

prompt: $(OBJETOS)
	$(LINKEAR) $(OBJETOS) -o prompt

backend: hashtable.o linkedList.o
	$(CC) hashtable.o linkedList.o

prompt.o: prompt.c
	$(CC) prompt.c -o prompt.o

hashtable.o: hashtable.c hashtable.h linkedList.h 
	$(CC) hashtable.c -o hashtable.o

linkedList.o: linkedList.c linkedList.h 
	$(CC) linkedList.c -o linkedList.o

clean:
	rm *.o prompt
	
	