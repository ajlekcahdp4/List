CC=gcc
CFLAGS= -Wall -Werror
all: main list
	$(CC) $(CFLAGS) main.o list.o -o list.out
main:
	$(CC) $(CFLAGS) -c main.c
list:
	$(CC) $(CFALGS) -c list.c
clean:
	rm -rf *.o *.out