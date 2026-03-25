#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  short l = -32765;
  unsigned short k = 32771;
  printf("l=%d, k=%u \n", l, k);
  printf("dump de l: \n");
  dump(&l, sizeof(l));
  printf("dump de k: \n");
  dump(&k, sizeof(k));
  return 0;
}

// short l 2 bytes 16 bits

// mod(-32765) = 32765
// 0111 1111 1111 1101
// inverto os bits e adiciono 1
// 1000 0000 0000 0010
// +                 1
//----------------------
// 1000 0000 0000 0011

// 8    0    0    3

// 0x.. -> 03
// 0x.. -> 80


//=============


// short k 2 bytes 16 bits

//Como o número não tem sinal não precisamos achar ele em binário, podemos encotrar direto em hexa 32771
//16ˆn <= 32771
//n = 4

//_ _ _ _

//m * 16ˆ3 <= 32771 -> m = 8
//
//32771 - 32768 = 3

// m * 16ˆ2 <= 3 --> m = 0

// m * 16ˆ1 <=3 --> m = 0

// m * 16ˆ0 <= 3 --> m = 3

// 0000 0000 0000 8003

// em little endian.
//03
//80
//00
//00

