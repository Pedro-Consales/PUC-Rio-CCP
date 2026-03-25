#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  char c = 150;
  short s = -3;
  int i = -151;
  printf("dump de c: \n");
  dump(&c, sizeof(c));
  printf("dump de s: \n");
  dump(&s, sizeof(s));
  printf("dump de i: \n");
  dump(&i, sizeof(i));
  return 0;
}


//Para char c transformando em binário
// char é 1 byte = 8 bits
// _ _ _ _ / _ _ _ _ = 1001 / 0110

// 96 em hexa onde 2 algarismos correspondem a um byte (8 bits)


//Para short s 
// _ _ _ _ / _ _ _ _ / _ _ _ _ / _ _ _ _

// 0 0 0 0 / 0 0 0 0 / 0 0 0 0 / 0 0 1 1 -> Mod(-3) = 3
// inverto os bits
// 1111 1111 1111 1100
// +.                1
//------------------------
// 1111 1111 1111 1101
//. F    F     F    D

//O Print em litle endian
// 0x... -> FD
// 0x... -> FF


//Para int i
// 0000 0000 0000 0000 1001 0111 mod(-151) =151
// inverto todos os bits 
// 1111 1111 1111 1111 0110 1000
// +                           1
//--------------------------------
// 1111 1111 1111 1111 0110 1001
// F.   F.    F.  F.    6.   9

// 0x... -> 69
// 0x... -> FF
// 0x... -> FF

