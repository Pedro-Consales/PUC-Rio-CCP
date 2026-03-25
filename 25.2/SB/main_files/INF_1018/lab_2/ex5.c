#include <stdio.h>

void dump (void *p, int n) {//endereço de i (=10000) e n = 4 (sizeof(int))
  unsigned char *p1 = p; //unsigner char represetna o menor tipo possível, 1 byte e *p1 aponta para o endereço de i, geralmente 1 byte (8 bits), conforme a implementação.
  printf("Códgo ASCII do %d\n", *p1);
  while (n--) { //enquanto não for zero, diminui um byte do contador de bytes
    printf("%p - %02x\n", p1, *p1);//print do %p = mostra o endereço do ponteiro - %x um numero inteiro sem sinal na base hexadecimal 02 é uma formatação extra para preencha 0 à esquerda e, 2, no máximo duas casa deciamos
    p1++;// Avança para o próximo byte
  }
}


int main (void) {
  char p[] = "A";
  
  dump(p, sizeof(p));
  return 0;
}

// 0x... - 37   → '7'
// 0x... - 35   → '5'
// 0x... - 30   → '0'
// 0x... - 39   → '9'
// 0x... - 00   → '\0' (terminador nulo)
// ``
