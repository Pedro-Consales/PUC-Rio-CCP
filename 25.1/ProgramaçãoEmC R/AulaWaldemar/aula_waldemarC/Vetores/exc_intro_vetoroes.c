#include <stdio.h>


// Escreva uma função que troca os valores armazenados em duas variáveis do tipo inteiro. Faça um programa que testa sua função e exibe os valores antes e depois da troca.
// Escreva uma função que recebe um vetor com 50 doubles e um valor X do tipo double, multiplica todos os elementos do vetor por X e retorna a soma dos novos elementos do vetor. 
// Faça um programa que testa sua função e imprime os valores antes e depois do vetor, além do valor retornado pela função.



int troca_valores(int *a, int* b )
{
    int temp = *b;
    *b = *a;
    *a = temp;

}


double soma_ele(double* vetor, double x)
{

    double soma = 0;

    for(int i = 0; i < 50; i++)
    {
        soma = soma + (vetor[i]*x); 

    }
    return soma;

}

int main(void)
{

    int a = 1;
    int b = 2;

    printf("Valor de A = %d\n",a);
    
    printf("Valor de B = %d\n\n",b);

    printf("***CHAMADA DA FUNCAO***\n\n");
    troca_valores(&a,&b);

    printf("Valor de A = %d\n",a);
    
    printf("Valor de B = %d\n\n",b);

    //==================================================================

    printf("***Teste da funao soma_ele***\n\n");

    double vetor[50] = {
     1,  2,  3,  4,  5,
     6,  7,  8,  9, 10,
    11, 12, 13, 14, 15,
    16, 17, 18, 19, 20,
    21, 22, 23, 24, 25,
    26, 27, 28, 29, 30,
    31, 32, 33, 34, 35,
    36, 37, 38, 39, 40,
    41, 42, 43, 44, 45,
    46, 47, 48, 49, 50};
    
    double x = 5;
    
    double soma = soma_ele(vetor, x);
    
    printf("A soma de cada elemento do vetor, depois que eh multiplicado por %.0f eh: %.2f",x, soma); 
    
    
    
    








}