gcc -E main.c -o main.i # preprocessor
gcc -S main.i -o main.s # compiler
as main.s -o main.o     # assembler
			# linker
ld /usr/lib/x86_64-linux-gnu/crti.o \
   /usr/lib/x86_64-linux-gnu/crtn.o \
   /usr/lib/x86_64-linux-gnu/crt1.o \
   -lc main.o -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o main_ELF_executablesavely@SavelyUBU:~/Рабочий стол
