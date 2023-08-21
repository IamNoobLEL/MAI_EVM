CC ?= gcc
CFLAGS ?= -Werror -pedantic
main: main.o iterator.o list.o
	${CC} -o main main.o iterator.o list.o

main.o: main.c 
	${CC} ${CFLAGS} -c main.c

iterator.o: iterator.c iterator.o
	${CC} ${CFLAGS} -c iterator.c

list.o: list.c list.o
	${CC} ${CFLAGS} -c list.c

clean: 
	rm -rf *.o main