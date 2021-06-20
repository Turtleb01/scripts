# My miscellaneous scripts

C projects can be compiled with
```
gcc -O3 -o <file> <file>.c
```

## uhex.c and hex.c

uhex.c is a simple implementation of UTF-8 as described in [Wikipedia](https://en.wikipedia.org/wiki/UTF-8#Encoding).
hex.c ignores unicode and just converts bytes.

Both take input from STDIN and output to STDOUT. There are no command line options. Usage example:

```
echo üäö |./uhex
```

Warning: there is absolutely no error checking, all kinds of problems are possible with incorrect input. I recommend using proper libraries for bigger projects.
