#include <stdio.h>

struct X {
  int a; //4 bytes
  short b;// 2 bytes
  int c;//4 bytes
};


void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - Hex: %02x / Dec: %d\n", p1, *p1, *p1);
    p1++;
  }
}

int main(void)
{
    struct X a = {0xa1a2a3a4, 0xb1b2, 0xc1c2c3c4};
    printf("Tamanho da struct: %zu\n", sizeof(a));

    dump(&a, sizeof(a));

    return 0;
}


//O endereço inicial começando em um múltiplo de 16 também é multiplo do int = 4 bytes

//Portanto o endereço começa sem padding.
//E então exibe guarda os 4 bytes, após os 4 bytes ainda é um endereço múltiplo de 2 que é o tamanho do proximo elemento
//Depois chega em um endereço que não é multiplo de 4, com isso ele é obrigado se não me engano terminado em 6
// então ele anda 2 bytes e entra em um endereço terminado em 8 que é multiplo de 4, por fim guarda o ultimo int nesse local

//Somando 4 + 2 + 2(padding)+ 4 = 12 bytes