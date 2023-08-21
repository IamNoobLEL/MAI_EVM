CC ?= gcc
CFLAGS ?= -Werror -pedantic
main: main.o table.o
	${CC} -o main main.o table.o

main.o: main.c 
	${CC} ${CFLAGS} -c main.c

functions.o: table.c table.o
	${CC} ${CFLAGS} -c table.c

clean: 
	rm -rf *.o main