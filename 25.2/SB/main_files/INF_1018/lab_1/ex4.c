#include <stdio.h>

void dump (void *p, int n);

int main() {
  char c1 = 1;
  char c2 = '1';
  int i = 1;
  char v[] = "1";

  printf("valor de c1: %d -> na memória: ",c1);
  dump(&c1, sizeof(c1));

  printf("\nvalor de c2: %d -> na memória: ",c2);
  dump(&c2, sizeof(c2));

  printf("\nvalor de i: %d -> na memória: ",i);
  dump(&i, sizeof(i));

  printf("\nvalor de v: %s -> na memória: ",v);
  dump(v, sizeof(v));

  printf("\n");
  return 0;
}

// Na chamada de dump, passamos o ENDEREÇO da variável (ou o decaimento do array para ponteiro)
// e a QUANTIDADE de bytes a imprimir. A função varre byte a byte e imprime o CONTEÚDO de cada byte.

// c1: é um número 1 armazenado em 1 byte (char). dump lê como unsigned char e imprime com %d -> 1.
// c2: é o caractere '1' (ASCII 49). dump imprime o valor numérico do byte -> 49.
// i:  é um int (tipicamente 4 bytes). Em máquina little-endian, 1 vira bytes 01 00 00 00 -> dump: 1 0 0 0.
// v:  é um array de 2 bytes {'1','\0'}. sizeof(v)==2. dump imprime 49 0. printf("%s", v) mostra "1".
