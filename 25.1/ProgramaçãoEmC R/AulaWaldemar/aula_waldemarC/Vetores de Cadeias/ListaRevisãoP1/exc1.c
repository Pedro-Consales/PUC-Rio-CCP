#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Questão 01) Escreva uma única função que recebe um vetor de inteiros e calcula duas somas: a soma dos 
// valores pares e a soma dos valores ímpares. Além do vetor e da quantidade inteiros no vetor, a função deve 
// receber ponteiros de variáveis onde as somas serão armazenadas.  


//Cabeçalho==========

void somaPar_e_Impares(int* vetor, int tamVetor, int* somaPar, int* somaImpar);

//Cabeçalho==========

int main(void)
{

    int tamVetor = 5;
    int somaPar;
    int somaImpar;

    int vetor[5] = {1,2,3,4,5};

    if(vetor == NULL)
    {
        printf("Erro ao alocar memoria para o vetor na main");
        exit(1);
    }


    somaPar_e_Impares(vetor,tamVetor, &somaPar, &somaImpar);

    printf("Soma dos numeros PARES: %d\n\n", somaPar);

    printf("Soma dos numeros IMPAR: %d", somaImpar);

    return 0;
}


//Funções==========


void somaPar_e_Impares(int* vetor, int tamVetor, int* somaPar, int* somaImpar)
{

    int somaPares = 0;
    int somaImpares = 0;
    for(int i = 0; i < tamVetor; i++)
    {
        if(vetor[i]%2 == 0)
        {
            somaPares += vetor[i];
        }
        else
        {
            somaImpares += vetor[i];
        }
    }

    *somaPar = somaPares;
    
    *somaImpar = somaImpares;
}