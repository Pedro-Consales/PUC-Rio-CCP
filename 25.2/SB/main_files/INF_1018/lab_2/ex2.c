#include <stdio.h>

void dump (void *p, int n) {//endereço de i (=10000) e n = 4 (sizeof(int))
  unsigned char *p1 = p; //unsigner char represetna o menor tipo possível, 1 byte e *p1 aponta para o endereço de i, geralmente 1 byte (8 bits), conforme a implementação.
  while (n--) { //enquanto não for zero, diminui um byte do contador de bytes
    printf("%p - %02x\n", p1, *p1);//print do %p = mostra o endereço do ponteiro - %x um numero inteiro sem sinal na base hexadecimal 02 é uma formatação extra para preencha 0 à esquerda e, 2, no máximo duas casa deciamos
    p1++;// Avança para o próximo byte
  }
}

int main (void) {
  long i = 10000; //Incializa e Declara i = 10000
  dump(&i, sizeof(i));//Chama a função Dump
  return 0;
}


//Tamanho em bytes de um long é = 8 bytes
//Estão ordenados no caso do meu PC em little endian então o menos significativo é impresso primeiro.


//No caso do long acontece a mesma coisa, porémm são mais bytes (8 bytes)

