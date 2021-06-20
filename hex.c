#include <stdio.h>

// this is the example cat program, but printf prints hexadecimal values instead
int main() {
  int c;
  while((c = getchar()) != EOF)
    printf("%02X ", c);
  printf("\n");
  return 0;
}
