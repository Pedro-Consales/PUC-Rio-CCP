#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** apenas_a(char** v,int *n, int tamVetorV);


int main(void)
{

    char* v[5] = {"Ana", "Bia", "Aurora", "Bruno", "Alan"};


    int n;
    char** w = apenas_a(v, &n, 5);

    for(int i = 0; i < n; i++)
    {

        printf("%s /", w[i]);


    }

    return 0;

}


char** apenas_a(char** v,int *n, int tamVetorV)
{

    int contA = 0;
    // Conta quantos nomes começam com 'A' ou 'a'
    for (int i = 0; i < tamVetorV; i++) {
        if (v[i][0] == 'A' || v[i][0] == 'a') {
            contA++;
        }
    }

    *n = contA;
    char** vetorDeA = (char**)malloc(contA * sizeof(char*));
    if(vetorDeA == NULL)
    {

        printf("Erro de alocação de memória no vetorDeA");
        exit(1);

    }

    int j = 0;
    for(int i = 0; i < tamVetorV; i++)
    {

        if(v[i][0] == 'A' || v[i][0] == 'a')
        {

            int tamStr = strlen(v[i]);

            char* strAtual = (char*)malloc((tamStr+1)*sizeof(char));

            strAtual = v[i];

            vetorDeA[j] = strAtual;

            j++;
        }    
    }


    return vetorDeA;
}