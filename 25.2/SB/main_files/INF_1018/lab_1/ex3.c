#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) { //O compilador entende que você ja quer contar alguma coisa qunado colocamos int como parâmetro na main. E com char** é o que voc6e vai armazenar o que você está passando no bash
  float f;
  if (argc!=2) {
    printf ("uso do programa: %s <valor float>\n", argv[0]);
    exit(0);
  }
  f = atof(argv[1]);
  printf ("foo(%.2f): %.2f\n", f, foo(f));
  return 0;
}

//Comandos para executar:
// Com tudo já rodado criado na parte de gerar o labux vamos fazer o teste sem o header da função
// Usamos gcc -Wall -o ex3 labaux.c ex3.c e ele gera o executável com os warnings de implicit declaration of function foo e também o que a função "expect"


//O código roda e chama a função foo(float pf) mas aparentemente o valor não aparece como deveria, parece que a função é chamada mas não tem por onde passar os parâmetros
//Input ./ex3 4.0
//Output -> foo(4.00): 00