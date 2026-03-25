/* programa 2*/
#include <stdio.h>

int main (void) {
  unsigned int x = 0xffffffff;
  unsigned int y = 2;
  printf("x=%u, y=%d\n", x, y);
  printf("x é menor do que y? %s\n", (x<y)?"sim":"nao");
  return 0;
}

// Quando armazenado em um int (signed), isso é interpretado em complemento de dois:

// O bit mais significativo (MSB) é 1, logo é um número negativo.

// Valor decimal: -1.



//Quando x é interpretado como sem sinal.

// 0xffffffff = 4294967295 (máximo valor em 32 bits sem sinal).

// y = 2.

// Comparação: x < y → 4294967295 < 2 → falso.