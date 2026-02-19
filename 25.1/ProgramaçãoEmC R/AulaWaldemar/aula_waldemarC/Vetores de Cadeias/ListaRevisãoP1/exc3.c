// Questão 03) Escreva uma única função que calcula a média aritmética e a média ponderada de um vetor de 
// float de tamanho qualquer. Além do vetor com os valores, a função recebe um segundo vetor com os pesos 
// da média ponderada. Ambas as médias devem ser passadas como parâmetros da função a serem 
// preenchidos.  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabeçalho==========

void medias(float* vetorValores, float* vetorPesos, int tamVetores, float* aritimetica, float* ponderada);

//Cabeçalho==========


int main(void)
{

    int tamVetor = 2;

    float vetorValores[2] = {7,8};

    float vetorPesos[2] = {2,3};

    float aritimetica;
    float ponderada;

    medias(vetorValores, vetorPesos, tamVetor, &aritimetica, &ponderada);

    printf("A media aritimerica eh %.2f\n\n", aritimetica);

    
    printf("A media aritimerica eh %.2f", ponderada);

}


//Função==========


void medias(float* vetorValores, float* vetorPesos, int tamVetores, float* aritimetica, float* ponderada)
{


    float somaAritimetica = 0;
    float somaPonderada = 0;
    float somaPesos = 0;

    float mediaAritimetica;
    float mediaPonderada;
    for(int i = 0; i < tamVetores; i++)
    {

        somaAritimetica += vetorValores[i];
        somaPonderada += (vetorValores[i]*vetorPesos[i]);
        somaPesos += vetorPesos[i];


    }
    mediaAritimetica = somaAritimetica/tamVetores;
    mediaPonderada = somaPonderada/somaPesos;

    *aritimetica = mediaAritimetica;
    *ponderada = mediaPonderada;

}