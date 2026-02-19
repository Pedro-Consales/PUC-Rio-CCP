#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct candidato
{
    int inscricao;
    char nome[51];
    int idade;
    float nota;
};
typedef struct candidato Candidato;

Candidato* criaCandidato(int inscricao, char* nome, int idade, float nota);
void exibeTodosCandidatos(Candidato** vetorDeCandidatos, int qtdCandidatos);
Candidato* buscaInscricao(Candidato** vetorDeCandidatos, int qtdCandidados, int inscricao);

int main (void)
{
    Candidato* vpcandidato[8];
    int i;
    int qtdCandidatos = 8;
    Candidato *cand;

    vpcandidato[0] = criaCandidato(444, "Luiz", 34, 7.8f);
    vpcandidato[1] = criaCandidato(111, "Rita", 56, 8.8f);
    vpcandidato[2] = criaCandidato(999, "Rute", 32, 7.1f);
    vpcandidato[3] = criaCandidato(555, "Dina", 27, 6.4f);
    vpcandidato[4] = criaCandidato(777, "Lana", 35, 5.3f);
    vpcandidato[5] = criaCandidato(666, "Tais", 29, 9.8f);
    vpcandidato[6] = criaCandidato(222, "Cris", 31, 7.2f);
    vpcandidato[7] = criaCandidato(333, "Vera", 44, 5.4f);

    exibeTodosCandidatos(vpcandidato, 8);

    /* inclua aqui a parte referente ao teste da função 
       buscaInscricao: leitura de uma inscrição, chamada da função e 
       exibição dos dados do candidato, se encontrado */
    int insc;
    printf("Agora, digite o numero de inscricao que voce deseja buscar: ");
    scanf("%d",&insc);
    cand = buscaInscricao(vpcandidato, qtdCandidatos, insc);

    printf("\n\n");

    if(cand != NULL)
    {
        printf("Candidato encontrado!\n\n");

        printf("Isc: %d\n", cand->inscricao);
        printf("Nome: %s\n", cand->nome);
        printf("Idade: %d\n",cand->idade);
        printf("Nota: %.2f\n", cand->nota);
    }




    for (i = 0; i < 8; i++)
        free(vpcandidato[i]);

    return 0;
}


Candidato* criaCandidato(int inscricao, char* nome, int idade, float nota)
{
    Candidato* nvCandiadto = (Candidato*)malloc(sizeof(Candidato));
    if(nvCandiadto == NULL)
    {
        printf("Erro ao alocar memoria para o novoCandidadto");
        return NULL;
    }

    nvCandiadto->inscricao = inscricao;
    strcpy(nvCandiadto->nome, nome);
    nvCandiadto->idade = idade;
    nvCandiadto->nota = nota;

    return nvCandiadto;
} 


void exibeTodosCandidatos(Candidato** vetorDeCandidatos, int qtdCandidatos)
{
    for(int i = 0; i < qtdCandidatos; i++)
    {
        Candidato* candidatoAtual = vetorDeCandidatos[i];

        printf("Candidato %d\n", i+1);
        printf("Isc: %d\n", candidatoAtual->inscricao);
        printf("Nome: %s\n", candidatoAtual->nome);
        printf("Idade: %d\n",candidatoAtual->idade);
        printf("Nota: %.2f\n", candidatoAtual->nota);

        printf("\n\n");

    }
}


Candidato* buscaInscricao(Candidato** vetorDeCandidatos, int qtdCandidados, int inscricao)
{

    for(int i = 0; i < qtdCandidados; i++)
    {
        Candidato* candidatoAtual = vetorDeCandidatos[i];

        if(candidatoAtual->inscricao == inscricao)
        {

            return candidatoAtual;

        }

    }
    printf("Nenhum candidato com essa inscricao localizado");
    return NULL;
}
