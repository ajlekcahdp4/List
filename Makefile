CC=gcc
CFLAGS= -Wall -Werror -Wextra -g
all: main list Dump
	$(CC) $(CFLAGS) main.o list.o Dump.o -o list.out
main:
	$(CC) $(CFLAGS) -c main.c
list:
	$(CC) $(CFLAGS) -c list.c
Dump:
	$(CC) $(CFLAGS) -c graphdump/Dump.c
clean:
	rm -rf *.o *.out *.png temp/ 