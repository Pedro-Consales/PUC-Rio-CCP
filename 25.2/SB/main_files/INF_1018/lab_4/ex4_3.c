/* programa 3*/
#include <stdio.h>

int main (void) {
  int x = 0xffffffff;
  unsigned int y = 2;
  printf("x=%d, y=%u\n", x, y);
  printf("x é menor do que y? %s\n", (x<y)?"sim":"nao");
  return 0;
}

// A variável x é declarada como signed int e recebe 0xffffffff, que em complemento de dois representa o valor -1. Já y é declarada como unsigned int e vale 2. Na hora da impressão com %d, o programa mostra x=-1 e y=2.

// Porém, quando ocorre a comparação (x < y), o C converte automaticamente o valor de x para unsigned, já que está sendo comparado com um unsigned int. Isso transforma -1 em 4294967295. Assim, a comparação real feita pelo compilador é:

//  4294967295 < 2