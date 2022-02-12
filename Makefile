CC=gcc
CFLAGS= -Wall -Werror
all: main list Dump
	$(CC) $(CFLAGS) main.o list.o Dump.o -o list.out
main:
	$(CC) $(CFLAGS) -c main.c
list:
	$(CC) $(CFALGS) -c list.c
Dump:
	$(CC) $(CFALGS) -c graphdump/Dump.c
clean:
	rm -rf *.o *.out *.png temp/ 