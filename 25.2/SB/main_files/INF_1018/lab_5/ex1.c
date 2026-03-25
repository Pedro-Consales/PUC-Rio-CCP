#include <stdio.h>

// int b[2]; -> [int, int] -> 2 * sizeof(int) = 8

// short a[2][3]; -> [[short, short, shor], [short, short, short]] -> 2*3*sizeof(short) = 12
void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  int i,j;
  short a[2][3];
  int b[2];

  for (i=0;i<2;i++) {
    b[i] = i;
    for (j=0;j<3;j++)
      a[i][j] = 3*i+j;
  }

  printf ("b: \n");
  dump (b, sizeof(b));
  printf ("a: \n");
  dump (a, sizeof(a));

  return 0;
}

//Demonstra dump da memória que o vetor guarda, byte a byte.
//E o resultado de acordo com o algorítimo de contagem.
