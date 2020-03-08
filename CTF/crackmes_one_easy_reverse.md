# Easy_reverse

[Download file](https://crackmes.one/crackme/5b8a37a433c5d45fc286ad83)

## Tool
* gdb-gef

## Solve
* check assembly by gdb
```
$ gdb-gef --args rev50_linux64-bit 1234567890
```

It check number of argument first, and string length second (= 10).

* Main condition
```
0x00000000000011f2 <+46>:	mov    rax,QWORD PTR [rbp-0x10]
0x00000000000011f6 <+50>:	add    rax,0x8
0x00000000000011fa <+54>:	mov    rax,QWORD PTR [rax]
0x00000000000011fd <+57>:	add    rax,0x4
0x0000000000001201 <+61>:	movzx  eax,BYTE PTR [rax]
0x0000000000001204 <+64>:	cmp    al,0x40
```
the cmp need to be equal.

* run debug to see the register 

# NOTICE
```
add rax, 0x4 ---> mean add 4 bytes !
```


```
(gdb) x/8w $rax
0x7fffffffe839:	0x34333231	0x38373635	0x53003039	0x4c4c4548
0x7fffffffe849:	0x73752f3d	0x69622f72	0x737a2f6e	0x534c0068
```
So `add rax, 0x4` will make rax = 0x00007fffffffe83d (0x38373635)

`al` is the right most 1 bytes

So the the 5th element should be ascii code : 40 (@)