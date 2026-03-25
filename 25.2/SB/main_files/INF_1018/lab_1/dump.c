#include <stdio.h>

void dump (void *p, int n) { //p é um ponteiro para um endereço de memória (void????)
  unsigned char *p1 = p;
  while (n--) {
    printf("%d ", *p1);
    p1++;
  }
}



