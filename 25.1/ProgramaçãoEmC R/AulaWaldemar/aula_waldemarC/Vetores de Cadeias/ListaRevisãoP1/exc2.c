// Questão 02) Escreva uma única função que aceita como parâmetros um vetor de inteiros v com n valores, 
// onde v e n são parâmetros da função, e determina o menor elemento do vetor e o número de vezes que este 
// elemento ocorreu no vetor. Por exemplo, para um vetor com os seguintes elementos: 5, 2, 15, 3, 7, 2, 15, 8, 
// 6, 15, a função terá como resultado o número 2 e o valor 2 (indicando que 2 é o menor número do vetor e que 
// o mesmo ocorreu 2 vezes). O valor mínimo e a quantidade de vezes devem ser informados em ponteiros 
// também recebidos como parâmetros na função. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabeçalho==========

int gravaMenor(int* vetor, int tamVetor, int* contMenor);
//Cabeçalho==========


int main(void)
{

    int tamVetor = 10; 
    int vetor[10] = {5, 2, 15, 2, 7, 2, 15, 8, 6, 15};
    int contMenor;

    int menor = gravaMenor(vetor, tamVetor, &contMenor);

    printf("O menor valor do vetor eh !!%d!! e ele ocorre %dx", menor, contMenor);

}


//Funções==========


int gravaMenor(int* vetor, int tamVetor, int* contMenor)
{

    int menor = vetor[0];
    int contadorMenor = 0;
    for(int i = 0; i < tamVetor; i++)
    {

        if(vetor[i] < menor)
        {

            menor = vetor[i];
            contadorMenor = 0;

        }
        if(vetor[i] == menor)
        {
            contadorMenor++;

        }
    }
    *contMenor =  contadorMenor;

    return menor;

}