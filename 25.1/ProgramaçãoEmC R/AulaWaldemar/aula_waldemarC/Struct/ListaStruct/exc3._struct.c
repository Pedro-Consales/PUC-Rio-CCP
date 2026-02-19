#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct grauDoAluno 
{ 
    float   prova; 
    float   avPratica; 
}; 
typedef struct grauDoAluno Grau; 

struct aluno 
{ 
    int mat; 
    char nome[51]; 
    Grau grau; 
}; 
typedef struct aluno Aluno;



Aluno* ciraAluno( int matricula, char* nome, float notaProva, float notaAvPratica);
void mostraAprovados(Aluno** vetorDeAlunos, int qtdAlunos);



int main(void)
{
    int qtdAlunos = 8;
    Aluno* vetorDeAlunos[8]; //Por que tem que ser asterístico deposi do Aluno sendo que eu ja estou declarando o vetor com o '[ ]'

    vetorDeAlunos[0] = ciraAluno(2410138,"Pedro Consales", 10.00, 5.00);
    vetorDeAlunos[1] = ciraAluno(2410139, "Ana Silva", 7.50, 2.00);
    vetorDeAlunos[2] = ciraAluno(2410140, "Carlos Souza", 4.00, 1.00);
    vetorDeAlunos[3] = ciraAluno(2410141, "Beatriz Lima", 8.00, 2.00);
    vetorDeAlunos[4] = ciraAluno(2410142, "João Pedro", 5.00, 1.50);
    vetorDeAlunos[5] = ciraAluno(2410143, "Mariana Costa", 6.00, 3.00);
    vetorDeAlunos[6] = ciraAluno(2410144, "Lucas Rocha", 3.00, 2.00);
    vetorDeAlunos[7] = ciraAluno(2410145, "Fernanda Alves", 9.00, 1.00);

    mostraAprovados(vetorDeAlunos, qtdAlunos);

    return 0;
}

Aluno* ciraAluno( int matricula, char* nome, float notaProva, float notaAvPratica)
{
    Aluno* student = (Aluno*)malloc(sizeof(Aluno));

    student->mat = matricula;
    strcpy(student->nome, nome); //Pode ser que dê merda
    student->grau.prova = notaProva;
    student->grau.avPratica = notaAvPratica;

    return student;
}

void mostraAprovados(Aluno** vetorDeAlunos, int qtdAlunos)
{
    for(int i = 0; i < qtdAlunos; i++)
    {   
        Aluno* alunoAtual = vetorDeAlunos[i];
        float grau = alunoAtual->grau.prova + alunoAtual->grau.avPratica;
        if(grau >= 5.0)
        {

            printf("O aluno %s de matricula %d obteve um grau total de %.2f",alunoAtual->nome, alunoAtual->mat, grau);

            printf("\n\n");
        }
    }
}