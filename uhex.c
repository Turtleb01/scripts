#include <stdio.h>

int main() {
  int c;
  while((c = getchar()) != EOF) {
//  by shifting the byte four bits right, we have the first four bits.
//  1111 = 15 -> 21-bit (4-byte) character
//  1110 = 14 -> 16-bit (3-byte) character
//  1100 = 13 -> 11-bit (2-byte) character
//  1101 = 12 -> 11-bit (2-byte) character
//  something else -> 7-bit ASCII character
//  https://en.wikipedia.org/wiki/UTF-8#Encoding
    switch(c >> 4) {
      case 15:
        c = (c - 240) * 262144;
//      there is no error checking, I just assume that the second,
//      third and fourth byte have first bits 1 and 0 properly set
        c += (getchar() - 128) * 4096;
        c += (getchar() - 128) * 64;
        c += (getchar() - 128);
        printf("%05X ", c);
        break;
      case 14:
        c = (c - 224) * 4096;
        c += (getchar() - 128) * 64;
        c += (getchar() - 128);
        printf("%04X ", c);
        break;
      case 13:
      case 12:
        c = (c - 192) * 64;
        c += (getchar() - 128);
        printf("%04X ", c);
        break;
      default:
        printf("%02X ", c);
    }
  }
//  one newline here before exit, so the next prompt appears on its own line
//  bash automatically removes it in process substitution $(command)
  printf("\n");
  return 0;
}
