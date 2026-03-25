#include <stdio.h>

int fat (int n);

int main (void) {
    int fatorial, n;
    n=5;
    fatorial = fat(n);
    printf("O núemro %d! é %d\n", n, fatorial);

   return 0;
}