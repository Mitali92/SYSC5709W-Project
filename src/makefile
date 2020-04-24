CC=gcc
CFLAGS=-I.
DEPS = database_lookup.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o database_lookup.o 
	$(CC) -o main main.o database_lookup.o
