#include <stdio.h>
#include <assert.h>

int check_eq(int x, int y) {
  return !(x ^ y);
}

int allOddBits(int x) {
  int mask = 0b10101010;
  int allOdds = mask | (mask << 8) | (mask << 16) | (mask << 24);
  printf("%0x\n", ((allOdds & x)));
  return !((allOdds & x) ^ x);
}

int main() {
  assert(check_eq(5, 4) == 0);
  assert(check_eq(10, 10) ==  1);
  assert(check_eq(13231, 2231) == 0);
  allOddBits(0x80000000);
  return 0;
}
