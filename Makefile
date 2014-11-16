all:
	gcc -g -m32 -fno-stack-protector -z execstack main.c -o main

dump:
	objdump -D main > out.txt

debug:
	gdb ./main

install:
	apt-get install g++-multilib libc6-dev-i386
