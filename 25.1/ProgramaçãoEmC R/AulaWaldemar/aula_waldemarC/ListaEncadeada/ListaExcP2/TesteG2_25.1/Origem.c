#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct aluno Aluno;
typedef struct lista Lista;
typedef struct no_lista NoLista;

struct aluno
{
    char nome[81];
    int matricula;
    float p1, p2;
};

struct no_lista {
    char nome[81];
    float media;
    NoLista* proximo;
};

struct lista {
    NoLista* primeiro;
};


Aluno* leia_arquivo(char* nome_arquivo, int* pn);
Lista* monta_lista(int n, Aluno* vet);
void imprime_aluno_vet(Aluno* al);
void imprime_aluno_lst(NoLista* no);
void imprime_encadeada(Lista* l);
Lista* obtem_lista_aprovados(Lista* listaEncadeada);



int main(void)
{
    int qtdAluno;//Crio a variável aluno

    Aluno* vetorDeAlunos = leia_arquivo("teste.txt", &qtdAluno);//Igualo o retorno da função à variavel aluno

    printf("Lista de Alunos:\n\n");
    for (int i = 0; i < qtdAluno; i++)//Loop da quantiade de alunos
    {
        imprime_aluno_vet(&vetorDeAlunos[i]);//Chamo a função imprime_aluno_vetor passando o endereço de uma posição do vetor de aluno, que É um aluno. Eu passo o endereço pois a função pede um ponteiro como parametro!
    }

    Lista* listaEndadeada = monta_lista(qtdAluno, vetorDeAlunos);//Iguala o retorno da função monta lista à variável listaEncaadeada

    printf("\n\n===============================\n\n");

    Lista* listaAlunosAprovados = obtem_lista_aprovados(listaEndadeada); //Igualo o retorno da função à variável listaAlunosAprovados;

    printf("Lista de Alunos Aprovados:\n\n");

    imprime_encadeada(listaAlunosAprovados);//Chamo a função que imprime a lista encadeada cpassando a lista dos allunos APROVADOS
   

    return 0;
}

Aluno* leia_arquivo(char* nome_arquivo, int* pn)
{

    FILE* arqEntrada = fopen(nome_arquivo, "rt");//Abro o arquivo para leitura
    if (arqEntrada == NULL)//Verificação de erro
    {
        printf("Erro ao abrir o arquivo de entrada");
        exit(1);
    }


    int qtdAluno;//Crio a variável qtd aluno
    fscanf(arqEntrada, " %d", &qtdAluno);//Leio do arquivo o valor que define a quantiade de aluos e guardo na variável qtdAluno
    *pn = qtdAluno;//Fala que o conteúdo do ponteiro pn é = ai valor de qtdAluno --> Nesse caso 10

    

    Aluno* vetorDeAluno = (Aluno*)malloc(qtdAluno * sizeof(Aluno));//Aloco espaço na memoria para o veotr de aluno;


    for (int i = 0; i < qtdAluno; i++)//Loop para ler cada linha do vetor
    {
        fscanf(arqEntrada, "  %[^:]: %d %f %f\n", vetorDeAluno[i].nome, &vetorDeAluno[i].matricula, &vetorDeAluno[i].p1, &vetorDeAluno[i].p2);//Leio uma linha e guardo na posição i do vetor de aluno. A poisção i do vetor de aluno é um Aluno.
    }

    fclose(arqEntrada);//Fecho o arquivo
    return vetorDeAluno;//Retorno o vetor
}

Lista* monta_lista(int n, Aluno* vet)
{

    Lista* l = (Lista*)malloc(sizeof(Lista));//Aloco memória para uma struct lista l
    if (l == NULL)//verificação de erro
    {
        printf("Erro ao alocar memoria para a lista");
        exit(1);
    }
    l->primeiro = NULL;//Digo que o elemento que a struct l guarda que é um ponteiro para NoLista é = NULL
    
    //Esse passo a passo de cima é como se fosse a função cria, mas sem criar a função
    

    for (int i = 0; i < n; i++)//Loop para copiar o valor dos elementos dos vetores para os elementos da lista encadeada
    {

        NoLista* p = (NoLista*)malloc(sizeof(NoLista));//Crio um elemento da lista encadeada.
        if (p == NULL)//Verificação de erro
        {
            printf("Erro ao alocar memoria para p");
            exit(1);
        }


        strcpy(p->nome, vet[i].nome);//Uso o strcpy (string copy) para copiar o vet[i].nome para p->nome vet[i] é o elemento da posição i do vetor que está sendo passado como parêmtro
        float media = (vet[i].p1 + vet[i].p2) / 2;//Calculo a média;
        p->media = media;//Copio o valor da media para dentro do elemento p que criei
        p->proximo = NULL;//Digo que o ponteiro para o proximo é = NULL

        if (l->primeiro == NULL)//Verifico se o primeiro elemento é NULL. Como a lista começa vazia, o ponteiro é NULL então na primeira interação é o único momento em que vai entrar nesse if
        {
            l->primeiro = p;//Agora o primiero que era NULL, passa a ser o elemento que criei na variável p.
        }
        else//Se não for NULL, é porque já existe um primeiro elemento, ou seja o elemento atual não é o primeiro
        {
            NoLista* e = l->primeiro;//Chamo uma variável de 'e' que aponta para o primeiro elemento
            while (e->proximo != NULL)//Enquanto o proximo do atual for diferente de NULL dentro do while andamos com ele
            {
                e = e->proximo;//Se o proximo do que está sendo verificado é diferente de NULL, o 'e' passa a ser o próximo e isso vai ficar sendo realizado até que e->proximo seja NULL
            }
            e->proximo = p;//Se chgou até aquim é por que o próximo do elemento atual é = NULL, logo eu digo que ele, vai ser o elemento p que criei la no início
        }
    }
    return l;//Retorno a lista
}

void imprime_aluno_vet(Aluno* al)
{
    printf("Nome completo: %s - matricula: %d - notas: %.2f %.2f\n", al->nome, al->matricula, al->p1, al->p2);
}


void imprime_aluno_lst(NoLista* no) 
{
    printf("Nome completo: %s - media: %f \n", no->nome, no->media);
}


void imprime_encadeada(Lista* l)
{
    NoLista* p = l->primeiro;
    while (p != NULL)
    {
        printf("Nome completo: %s - media: %f \n", p->nome, p->media);
        p = p->proximo;
    }
}

Lista* obtem_lista_aprovados(Lista* listaEncadeada)//Essa função tem a mesma lógica que a monta_lista a unica diferença é qe antes de cirar o elemento tem que haver a verificaçaõ dos casos e percorrer as duas listas juntas
{

    Lista* l = (Lista*)malloc(sizeof(Lista));
    if (l == NULL)
    {
        printf("Erro ao alocar memoria para a lista");
        exit(1);
    }
    l->primeiro = NULL;
    //Como se fosse a função cria, mas sem criar
    
    NoLista* elemento = listaEncadeada->primeiro;
    while (elemento != NULL)
    {
        if (elemento->media >= 6)
        {
            NoLista* p = (NoLista*)malloc(sizeof(NoLista));
            if (p == NULL)
            {
                printf("Erro ao alocar memoria para p");
                exit(1);
            }

            strcpy(p->nome, elemento->nome);
            p->media = elemento->media;
            p->proximo = NULL;

            if (l->primeiro == NULL)
            {
                l->primeiro = p;
            }
            else
            {
                NoLista* e = l->primeiro;
                while (e->proximo != NULL)
                {
                    e = e->proximo;
                }
                e->proximo = p;
            }
            
        }
        elemento = elemento->proximo;
    }
    return l;
}