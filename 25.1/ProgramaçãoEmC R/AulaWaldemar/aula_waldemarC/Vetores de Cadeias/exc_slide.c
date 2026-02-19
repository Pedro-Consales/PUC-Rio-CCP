#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTDNOTAS 3


// 1. Leia uma sequencia de nomes e notas de alunos: primeiro, leia
// o numero de alunos; depois para cada aluno, leia seu nome
// completo na primeira linha, seguido por tres notas. A nota
// nal de cada aluno e a media das tres notas. Seu programa
// deve exibir na tela a media das notas nais entre os alunos e
// informar os nomes dos alunos, seguido de suas notas nais,
// que estao acima e os nomes dos que estao abaixo da media,
// tambem seguidos de suas notas nais. Gaste o espaco de
// memoria estritamente necessario para armazenar as
// informacoes recebidas. Nao esqueca de liberar a memoria
// apos seu uso.


//Cabeçalho:================================


//Cabeçalho:================================

int main(void)
{

    int qtdAlunos;
    
    char nome[150];
    float bufferNota;

    printf("Digite a quantiade de alunos: ");
    scanf("%d", &qtdAlunos);

    printf("\n\n");

    char** vetorNomeAlunos = (char**)malloc(qtdAlunos*sizeof(char*));
    if( vetorNomeAlunos == NULL)
    {

        printf("Erro ao alocar memoria para o vetor de nomes dos alunos");
        return 1;

    }

    float** vetorNotasAlunos = (float**)malloc(qtdAlunos*sizeof(int*));
    if( vetorNotasAlunos == NULL)
    {

        printf("Erro ao alocar memoria para o vetor de notas dos alunos");
        return 1;

    }

    for(int i = 0; i < qtdAlunos; i++)
    {

        printf("Para o aluno %d \n", i+1);
        printf("Digite o nome do aluno: ");
        scanf("%s", nome);

        vetorNomeAlunos[i] = (char*)malloc((strlen(nome)+1)*sizeof(char));
        if (vetorNomeAlunos[i] == NULL) {
            printf("Erro ao alocar memória para o nome do aluno.\n");
            return 1;
        }

        strcpy(vetorNomeAlunos[i], nome);

        printf("\n");

        float* notasAtuais = (float*)malloc(QTDNOTAS * sizeof(float));
        if( notasAtuais == NULL)
        {
            printf("Erro ao alocar memoria para o vetor de notas ATUAIS dos alunos");
            return 1;
        }


        for(int j = 0; j < QTDNOTAS; j++)
        {

            printf("Digite a nota desse aluno: ");
            scanf("%f", &bufferNota);
            notasAtuais[j] = bufferNota;

        }

        
        vetorNotasAlunos[i] = notasAtuais;

        printf("\n\n");
    }
 


    float soma = 0;
    float media;
    for(int i = 0; i < qtdAlunos; i++)
    {

        printf("%s: ",vetorNomeAlunos[i]);

        for(int j = 0; j < QTDNOTAS; j++)
        {

            soma += vetorNotasAlunos[i][j];
            printf("%.1f / ", vetorNotasAlunos[i][j]);

        }  
        media = soma/3;
        if(media < 5)
        {

            printf(" -->  A media do aluno eh: %.1f", media);


        }
        else{

            printf(" -->  A media do aluno eh: %.1f", media);

        }
        printf("\n\n");
        media = 0;
        soma = 0;
    }

    for(int i = 0; i <qtdAlunos; i++)
    {

        for(int j = 0; j < QTDNOTAS; j++)
        {

            soma += vetorNotasAlunos[i][j];

        }  
        media = soma/3;

        printf("!!!MEDIA %.2f !!!", media);

        if(media < 5)
        {

            printf("O aluno %s esta ABAIXO DA MEDIA\n\n", vetorNomeAlunos[i]);
            soma = 0;
            media = 0;

        }
        else{


            printf("O aluno %s esta ACIMA DA MEDIA\n\n", vetorNomeAlunos[i]);
            soma = 0;
            media = 0;

        }
        


    }


    //Falta dar free.
    return 0;
}



//Funções:================================
