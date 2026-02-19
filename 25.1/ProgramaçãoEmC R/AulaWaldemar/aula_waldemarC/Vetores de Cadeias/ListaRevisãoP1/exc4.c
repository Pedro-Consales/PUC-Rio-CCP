// Questão 04) Escreva uma função que recebe um vetor de inteiros e retorna um novo vetor, alocado 
// dinamicamente, eliminando os elementos repetidos em sequência. Por exemplo, dado {1,2,2,1,4,5,6,6,5} , a 
// função deve criar o vetor {1,2,1,4,5,6,5}. A função deve retornar o novo vetor e receber um parâmetro para 
// preencher a quantidade de elementos inseridos no novo vetor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabeçalho==========

int* elimSeguidos(int *vetor, int tamVetor );

//Cabeçalho==========



int main(void)
{
    int tamVetor = 9;
    int vetor[9] = {1,2,2,1,4,5,6,6,5};

    elimSeguidos(vetor, tamVetor );



}

//Funções==========


int* elimSeguidos(int *vetor, int tamVetor )
{

    int contNSeguidos = 0;
    for(int i = 0; i < tamVetor-1; i++)
    {
        printf("Comparando %d == %d\n", vetor[i], vetor[i+1]);
      
        if(vetor[i] != vetor[i+1])
        {
           
            contNSeguidos++;


        }
                
        printf("Elemento: %d / i: %d /cont: %d\n\n", vetor[i],i, contNSeguidos);
    }


}