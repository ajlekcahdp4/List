CC=gcc
CFLAGS= -Wall -Werror -Wextra -g
all: main list DtDump
	$(CC) $(CFLAGS) main.o list.o DtDump.o -o list.out
main:
	$(CC) $(CFLAGS) -c main.c
list:
	$(CC) $(CFLAGS) -c list.c
DtDump :
	$(CC) $(CFLAGS) -c graphdump/DtDump.c
clean:
	rm -rf *.o *.out *.png temp/ 