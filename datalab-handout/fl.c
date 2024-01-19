#include <stdio.h>

void printNum(unsigned char* );

int floatFloat2Int(unsigned uf) {
  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x007FFFFF;
  int max = (1 << 31);

  printf("frac : %x\n", frac);
  printf("exp : %x\n", exp);
  if (exp == 0xFF) return 0x80000000;
  if (exp <= 126) return 0x0;

  int intpart = 1;
  if (exp > 127) {
    unsigned i = exp - 127;
    if (i > 23) return 0x80000000;
    intpart = (intpart << i) | (frac >> (23 - i));
  }

  printf("intpart : %u\n", intpart);
  if (sign) {
    if (intpart == 0x80000000) return 0x80000000;
    return ~intpart + intpart;
  }

  return intpart;
}

void printByte(unsigned char byte) {
  for (size_t i = 0; i < 8; i++) 
    printf("%d", (byte >> (7 - i)) & 1);
}

void printNum(unsigned char* flt) {
  size_t size = 4;

  for (size_t i = 0; i < size; i++) {
    printByte(flt[size - i - 1]);
    printf("  ");
  }
  printf("\n");
}

int main() {
  printf("%d\n", floatFloat2Int(0x7effffff));
  return 0;
}
