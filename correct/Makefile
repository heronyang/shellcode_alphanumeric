all:
	gcc -g -m32 -fno-stack-protector -z execstack correct.c -o correct

dump:
	objdump -M intel -D ./correct > out.txt

debug: all
	gdb ./correct
