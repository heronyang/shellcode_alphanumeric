all:
	gcc -g -m32 -fno-stack-protector -z execstack main.c -o main

dump:
	objdump -M intel -D ./main > out.txt

run: all
	./sc_gen.py > input.txt
	./main < input.txt

debug: all
	./sc_gen.py > input.txt
	gdb ./main

install:
	apt-get install g++-multilib libc6-dev-i386
