# WhitePages

given a file :
```
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
```

yes, it is all space

use `file`, `strings` still can't find something fun.
try open in hex mode :

```
00000000  e2 80 83 e2 80 83 e2 80  83 e2 80 83 20 e2 80 83  |............ ...|
00000010  20 e2 80 83 e2 80 83 e2  80 83 e2 80 83 e2 80 83  | ...............|
00000020  20 e2 80 83 e2 80 83 20  e2 80 83 e2 80 83 e2 80  | ...... ........|
00000030  83 e2 80 83 20 e2 80 83  e2 80 83 20 e2 80 83 20  |.... ...... ... |
00000040  20 20 e2 80 83 e2 80 83  e2 80 83 e2 80 83 e2 80  |  ..............|
00000050  83 20 20 e2 80 83 20 e2  80 83 e2 80 83 20 e2 80  |.  ... ...... ..|
00000060  83 20 20 e2 80 83 e2 80  83 e2 80 83 20 20 e2 80  |.  .........  ..|
00000070  83 20 20 e2 80 83 20 20  20 20 e2 80 83 20 e2 80  |.  ...    ... ..|
00000080  83 e2 80 83 e2 80 83 e2  80 83 20 20 e2 80 83 20  |..........  ... |
00000090  e2 80 83 20 e2 80 83 20  e2 80 83 e2 80 83 e2 80  |... ... ........|
000000a0  83 20 e2 80 83 e2 80 83  e2 80 83 20 20 e2 80 83  |. .........  ...|
000000b0  e2 80 83 e2 80 83 e2 80  83 e2 80 83 20 e2 80 83  |............ ...|
000000c0  20 e2 80 83 e2 80 83 e2  80 83 e2 80 83 e2 80 83  | ...............|
000000d0  20 e2 80 83 20 e2 80 83  e2 80 83 e2 80 83 e2 80  | ... ...........|
000000e0  83 e2 80 83 20 e2 80 83  e2 80 83 20 e2 80 83 e2  |.... ...... ....|
000000f0  80 83 e2 80 83 e2 80 83  20 e2 80 83 e2 80 83 20  |........ ...... |
00000100  e2 80 83 20 e2 80 83 20  e2 80 83 e2 80 83 20 20  |... ... ......  |
00000110  e2 80 83 20 e2 80 83 e2  80 83 e2 80 83 20 e2 80  |... ......... ..|
00000120  83 20 e2 80 83 20 e2 80  83 e2 80 83 e2 80 83 20  |. ... ......... |
00000130  e2 80 83 20 e2 80 83 e2  80 83 20 e2 80 83 e2 80  |... ...... .....|
00000140  83 e2 80 83 e2 80 83 e2  80 83 e2 80 83 20 e2 80  |............. ..|
00000150  83 20 e2 80 83 e2 80 83  e2 80 83 e2 80 83 e2 80  |. ..............|
00000160  83 20 e2 80 83 20 e2 80  83 20 e2 80 83 20 e2 80  |. ... ... ... ..|
00000170  83 20 e2 80 83 e2 80 83  e2 80 83 e2 80 83 20 e2  |. ............ .|
00000180  80 83 e2 80 83 20 e2 80  83 e2 80 83 20 20 e2 80  |..... ......  ..|
00000190  83 e2 80 83 e2 80 83 20  e2 80 83 e2 80 83 20 e2  |....... ...... .|
000001a0  80 83 e2 80 83 20 e2 80  83 20 e2 80 83 e2 80 83  |..... ... ......|
```
(not all)

It seems that there are two things !

1. e2 80 83 ==> ' '
2. 20 => '.'

Googling e28083, it seems the unicode character 'EM SPACE'

convert them with 1 and 0

```python
# for unbits
from pwn import * 

f = open("whitepages.txt", "rb")
data = bytearray(f.read()) # let byte convert to string
data = data.replace(b'\xe2\x80\x83', b'0')
data = data.replace(b'\x20', b'1')
data = data.decode('ascii')
print(unbits(data)) # unbits convert byte to string 
```
