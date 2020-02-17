# c0rrupt

It's fun, but fucking hard...

check file first :
```
mystery: data
```

open in hex mode :
```
>>> hexdump -C mystery| head
00000000  89 65 4e 34 0d 0a b0 aa  00 00 00 0d 43 22 44 52  |.eN4........C"DR|
00000010  00 00 06 6a 00 00 04 47  08 02 00 00 00 7c 8b ab  |...j...G.....|..|
00000020  78 00 00 00 01 73 52 47  42 00 ae ce 1c e9 00 00  |x....sRGB.......|
00000030  00 04 67 41 4d 41 00 00  b1 8f 0b fc 61 05 00 00  |..gAMA......a...|
00000040  00 09 70 48 59 73 aa 00  16 25 00 00 16 25 01 49  |..pHYs...%...%.I|
00000050  52 24 f0 aa aa ff a5 ab  44 45 54 78 5e ec bd 3f  |R$......DETx^..?|
00000060  8e 64 cd 71 bd 2d 8b 20  20 80 90 41 83 02 08 d0  |.d.q.-.  ..A....|
00000070  f9 ed 40 a0 f3 6e 40 7b  90 23 8f 1e d7 20 8b 3e  |..@..n@{.#... .>|
00000080  b7 c1 0d 70 03 74 b5 03  ae 41 6b f8 be a8 fb dc  |...p.t...Ak.....|
00000090  3e 7d 2a 22 33 6f de 5b  55 dd 3d 3d f9 20 91 88  |>}*"3o.[U.==. ..|
```

See the bits `89 65 4e 34` ? It looks like [`png header`](https://www.wikiwand.com/en/Portable_Network_Graphics#/File_format) !

## header
So first change the header to png format.
```
00000000  89 50 4e 47 0d 0a 1a 0a  00 00 00 0d 43 22 44 52  |.PNG........C"DR|
```

```
>>> pngcheck -v mystery
File: mystery (202940 bytes)
  invalid chunk name "C"DR" (43 22 44 52)
ERRORS DETECTED in mystery 
```

## chunck
Next is chunck. PNG have some important chunck :
```
an IHDR chunck
one or more IDAT chunks
an IEND chunck
```
see [`this`](http://www.libpng.org/pub/png/spec/1.2/PNG-Chunks.html)

The length of the chunck is :

|length        | chunck type  | chunck data | CRC |
|:------------:|:------------:|:-----------:|:---:|
|4 bytes    | 4 bytes |  length bytes | 4 bytes |

So modify `C"DR` to `IHDR` 
```
00000000  89 50 4e 47 0d 0a 1a 0a  00 00 00 0d 49 48 44 52  |.PNG........IHDR|
```

```
>>> pngcheck -v mystery
File: mystery (202940 bytes)
  chunk IHDR at offset 0x0000c, length 13
    1642 x 1095 image, 24-bit RGB, non-interlaced
  chunk sRGB at offset 0x00025, length 1
    rendering intent = perceptual
  chunk gAMA at offset 0x00032, length 4: 0.45455
  chunk pHYs at offset 0x00042, length 9: 2852132389x5669 pixels/meter
  CRC error in chunk pHYs (computed 38d82c82, expected 495224f0)
ERRORS DETECTED in mystery
```

CRC ERROR :
```
00000040  00 09 70 48 59 73 aa 00  16 25 00 00 16 25 01 49  |..pHYs...%...%.I|
00000050  52 24 f0 aa aa ff a5 ab  44 45 54 78 5e ec bd 3f  |R$......DETx^..?|
```
change `49 52 24 f0` to `28 d8 2c 82`
```
00000040  00 09 70 48 59 73 aa 00  16 25 00 00 16 25 01 38  |..pHYs...%...%.8|
00000050  d8 2c 82 aa aa ff a5 ab  44 45 54 78 5e ec bd 3f  |.,......DETx^..?|
```

check again
```
>>> pngcheck -v mystery
File: mystery (202940 bytes)
  chunk IHDR at offset 0x0000c, length 13
    1642 x 1095 image, 24-bit RGB, non-interlaced
  chunk sRGB at offset 0x00025, length 1
    rendering intent = perceptual
  chunk gAMA at offset 0x00032, length 4: 0.45455
  chunk pHYs at offset 0x00042, length 9: 2852132389x5669 pixels/meter
:  invalid chunk length (too large)
ERRORS DETECTED in mystery
```

```
00000050  d8 2c 82 aa aa ff a5 ab  44 45 54 78 5e ec bd 3f  |.,......DETx^..?|
```

What is DET??? Maybe It is `IDAT` !\
So change it to IDAT\
check again :
```
File: mystery (202940 bytes)
  chunk IHDR at offset 0x0000c, length 13
    1642 x 1095 image, 24-bit RGB, non-interlaced
  chunk sRGB at offset 0x00025, length 1
    rendering intent = perceptual
  chunk gAMA at offset 0x00032, length 4: 0.45455
  chunk pHYs at offset 0x00042, length 9: 2852132389x5669 pixels/meter
:  invalid chunk length (too large)
ERRORS DETECTED in mystery
```

```
00000050  d8 2c 82 aa aa ff a5 ab  44 45 54 78 5e ec bd 3f  |.,......DETx^..?|
```
`aa aa ff a5` is too long, so I change it to `00 00 ff a5` 

check :
```
File: mystery (202940 bytes)
  chunk IHDR at offset 0x0000c, length 13
    1642 x 1095 image, 24-bit RGB, non-interlaced
  chunk sRGB at offset 0x00025, length 1
    rendering intent = perceptual
  chunk gAMA at offset 0x00032, length 4: 0.45455
  chunk pHYs at offset 0x00042, length 9: 2852132389x5669 pixels/meter
  chunk IDAT at offset 0x00057, length 65445
    zlib: deflated, 32K window, fast compression
  chunk IDAT at offset 0x10008, length 65524
  chunk IDAT at offset 0x20008, length 65524
  chunk IDAT at offset 0x30008, length 6304
  chunk IEND at offset 0x318b4, length 0
No errors detected in mystery (9 chunks, 96.3% compression).
```

No errors ! hurray!!


more information : [this](https://hackmd.io/@FlsYpINbRKixPQQVbh98kw/Bk9Wj63vH)
