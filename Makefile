CC=gcc
CFLAGS= -Wall -Werror -Wextra
all: main list HTMLdump DtDump
	$(CC) $(CFLAGS) main.o list.o dump.o DtDump.o -o list.out
main:
	$(CC) $(CFLAGS) -c main.c
list:
	$(CC) $(CFLAGS) -c list.c
HTMLdump:
	$(CC) $(CFLAGS) -c dump/dump.c
DtDump :
	$(CC) $(CFLAGS) -c graphdump/DtDump.c
clean:
	rm -rf *.o *.out *.png  *.html temp/ logs/* 