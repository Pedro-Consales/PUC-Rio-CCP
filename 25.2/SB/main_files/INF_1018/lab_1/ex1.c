#include <stdio.h>
#include <stdlib.h>

float foo (float pf) {
  return pf+1;
}

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
//gcc -Wall -o ex1 ex1.c (Faça o meu executável)
//Esse comando faz gerar um output escrito ex1 vindo do arquivo ex1.c "-o ex1 ex1.c", o executável

//Na execução desse arquivo
//Input terminal: ./ex1 4.0
//Resultado: foo(4.00): 5.00
//O que acontece no código é que qunado chamamos a main, passamos os parâmetros dizendo como primeiro argumento qual executável queremos rodar e o segundo argumento é o valor float então o progema chama o executável ./ex1 e o valor float para passar na função "foo()"
//O código roda e chama a função foo(float pf) que retorna o valor float somado + 1
//O parâmetro argc é automaticamente interpretado pelo compilador como um contador de elementos, por ser int.
//Então tudo que eu boto depois é fechado como string ex: ./ex1 4.0 (são duas strings, que dentro do programa a string de numero vira um float)

//Quando rodamos o arquivo apneas com ./ex1
//Resultado:
//uso do programa: ./ex1 <valor float> (ele espera um segundo parâmetro)

//Quando rodamos ex1
//erro-> bash: ex1: command not found
//Por que é preciso do ./ devido ao path. Como eu já estou no diretório onde tem o executável não precsio indicar o caminho
