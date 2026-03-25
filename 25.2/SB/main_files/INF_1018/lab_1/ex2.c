#include <stdio.h>
#include <stdlib.h>

float foo (float pf);

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
// Compilação labaux: gcc -Wall -c labaux.c 
// Compilação de ex2:  gcc -Wall -c ex2.c  (Compile gcc -Wall -c ex2.c )
// Ligando os módulos:  gcc -o ex2 labaux.o ex2.o
// Ou rode tudo de uma vez: gcc -Wall -o ex2 labaux.c ex2.c
// Esses comando faz a ligação dos móduglo ("Objetos") e geram um output escrito ex2 vindo do arquivo ex2.c "-o ex2 ex2.c", o executável

//Na execução desse arquivo
//Input terminal: ./ex2 4.0
//Resultado: foo(4.00): 5.00
//O que acontece no código é compilamos os módulos e importamos ele dentro do código fonte onde ciramos a main. Quando chamaos o executável, inicia-se a main e passamos os parâmetros dizendo como primeiro argumento qual executável queremos rodar e o segundo argumento é o valor float então o progema chama o executável ./ex1 e o valor float para passar na função "foo()"

//Quando rodamos o arquivo apneas com ./ex2
//Resultado:
//uso do programa: ./ex2 <valor float> (ele espera um segundo parâmetro)