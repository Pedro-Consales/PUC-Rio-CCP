// Questão 11) Implemente uma função que recebe como parâmetros dois vetores de inteiros, v1 e v2, e as 
// suas respectivas quantidades de elementos, n1 e n2. A função também deve receber um terceiro vetor v3, 
// com capacidade para (n1 + n2) elementos. Sua função deverá inserir os elementos de v1 e v2 em v3 de modo 
// intercalado. Por exemplo, se v1 = {1, 3, 5, 7} e v2 = {2, 4, 6, 8, 10, 12}, v3 irá conter {1, 2, 3, 4, 5, 6, 7, 8, 10, 
// 12}. Observe que dependendo do número de elementos, os últimos valores podem não ficar intercalados. 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void intercala(int* v1, int n1, int* v2, int n2, int* v3);



int main(void)
{
    int n1 = 4;
    int n2 = 6;
    int n3 = 10;

    int v1[4] = {1, 3, 5, 7};
    int v2[6] = {2, 4, 6, 8, 10, 12};
    int v3[10];

    for(int i = 0; i < n3; i++)
    {

        printf("%d ", v3[i]);

    }

}



void intercala(int* v1, int n1, int* v2, int n2, int* v3)
{
    int tamMenor;
    int tamMaior;
    if(n1>n2)
    {
        tamMenor = n2;
        tamMaior = n1;
    }
    else if(n1<n2)
    {
        tamMenor = n1;
        tamMaior = n2;
    }
    else if(n1==n2)
    {
        tamMenor = n1;
        tamMaior = n1;
    }

    int k = 0;
    int j = 0;
    int x = 0;
    for(int i = 0; i < tamMaior; i++)
    {
        if(x == tamMaior)
        {
            v3[k] = v1[x];;
            k++;
            x++;

        }
        if(j == tamMaior)
        {
            v3[k] = v2[j];
            k++;
            j++;

        }
        
    }

}