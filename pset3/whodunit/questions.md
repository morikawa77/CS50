# Questions

## What's `stdint.h`?

It's a file to help to create more portable codes and provide width for integer types and helps for files who demanding considerable hardware manipulation.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Provide a exact width sizes for integer types.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?
BYTE has 1 byte
DWORD has 4 bytes (32 bits)
LONG has 4 bytes (32 bits)
WORD has 2 bytes (16 bits)


## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII B e ASCII M

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the bmp file in bytes. biSize is the size of the structure in bytes.

## What does it mean if `biHeight` is negative?

The image is bottom down.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

If the file that fopen is trying to write doesn't exist it will return NULL.

## Why is the third argument to `fread` always `1` in our code?

Because we are iterating over every pixel.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4 = 3.
This step ensures the number of bytes in every row is a multiple of 4.

## What does `fseek` do?

fseek allows us to change the offset of a pointer.

## What is `SEEK_CUR`?

SEEK_CUR is the current position indicator in the file.
