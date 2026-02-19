#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct termo
{
    int coeficiente;
    int expoente;
};
typedef struct termo Termo;

Termo* criaSoma(Termo* vetor_deTermos1, Termo* vetor_deTermos2, int *tam1, int *tam2, int* tamNovoVetor);

int main(void)
{
    Termo vetor_Termos1[] = { {5,6}, {8,3}, {1,2}, {7,0} };
    int tam1 = 4;

    Termo vetor_Termos2[] = { {2,4}, {7,2} };
    int tam2 = 2;

    int tamNovoVetor;

    Termo* nvVetor = criaSoma(vetor_Termos1, vetor_Termos2, &tam1, &tam2, &tamNovoVetor);

    for(int i = 0; i < tamNovoVetor; i++)
    {

        printf("%d*x^%d ",nvVetor[i].coeficiente,nvVetor[i].expoente);
        printf(" + ");

    }
    
}

Termo* criaSoma(Termo* vetor_deTermos1, Termo* vetor_deTermos2, int *tam1, int *tam2, int* tamNovoVetor)
{

    Termo* novoVetor = (Termo*)malloc((*tam1+*tam2)*sizeof(Termo));


    int i = 0, j = 0, k = 0;

    while (i < *tam1 && j < *tam2)
    {

        if(vetor_deTermos1[i].expoente > vetor_deTermos2[j].expoente)
        {

            novoVetor[k] = vetor_deTermos1[i];
            k++;
            i++;
        }
        else if(vetor_deTermos1[i].expoente < vetor_deTermos2[j].expoente)
        {
            novoVetor[k] = vetor_deTermos2[j];
            k++;
            j++;
        }
        else
        {
            novoVetor[k].coeficiente = vetor_deTermos1[i].coeficiente+vetor_deTermos2[j].coeficiente;
            novoVetor[k].expoente = vetor_deTermos1[i].expoente;
            k++;
            i++;
            j++;
        }
        
    }

    while (i < *tam1) novoVetor[k++] = vetor_deTermos1[i++];
    while (j < *tam2) novoVetor[k++] = vetor_deTermos2[j++];

    *tamNovoVetor = k;

    return novoVetor;
}



        // if(vetor_deTermos2[i].expoente > vetor_deTermos1[j].expoente)
        // {
            
        //     novoVetor[k].coeficiente = vetor_deTermos2[i].coeficiente;
        //     novoVetor[k].expoente = vetor_deTermos2[i].expoente;

        //     j++;
        //     k++;
        // }
        // else if(vetor_deTermos2[i].expoente == vetor_deTermos1[j].expoente)
        // {

        //     int soma = vetor_deTermos2[i].coeficiente + vetor_deTermos1[j].coeficiente;
            
        //     novoVetor[k].coeficiente = soma;
        //     novoVetor[k].expoente = vetor_deTermos1[j].expoente;

        //     j++;
        //     k++;
        // }
        // else if(vetor_deTermos2[i].expoente < vetor_deTermos1[j].expoente)
        // {

        //     novoVetor[k].coeficiente = vetor_deTermos1[i].coeficiente;
        //     novoVetor[k].expoente = vetor_deTermos1[i].expoente;

        //     j++;
        //     k++;

        // }
