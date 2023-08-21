CC ?= gcc
CFLAGS ?= -Werror -pedantic
main: main.o stack.o token.o tree.o
	${CC} -o main main.o stack.o token.o tree.o

main.o: main.c 
	${CC} ${CFLAGS} -c main.c

stack.o: stack.c stack.h
	${CC} ${CFLAGS} -c stack.c

token.o: token.c token.h
	${CC} ${CFLAGS} -c token.c

tree.o: tree.c tree.h
	${CC} ${CFLAGS} -c tree.c

clean: 
	rm -rf *.o main