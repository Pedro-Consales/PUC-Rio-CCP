//Pedro Consales Margaronis e Gabriel


#include <stdio.h>
#include <stdlib.h>


typedef struct nodo No;
typedef struct arvore Arvore;

#define qtdChaves 20



struct nodo
{
    int chave;
    No* esq;
    No* dir;
};

struct arvore
{
    No* raiz;
};

Arvore* criaArv();
void readArq(char* nome, int* vetor);
No* insere(Arvore* arv, int chave);
void exibe_simetrica(No *p);
void exibe_preordem(No *p);
void exibe_por_nivel(No *p);


int main(void)
{

    int vetor[qtdChaves];

    readArq("entrada2.txt", vetor);

    Arvore* arv = criaArv();
    No* no;

    //Fazer fila 
    for(int i = 0; i < qtdChaves; i++)
    {
        int numAtual = vetor[i];
        no = insere(arv, numAtual);
    }

    printf("\nPrint da por nivel!\n\n");
    exibe_por_nivel(arv->raiz);
    printf("\n============\n\n");


    printf("\nPrint da forma simétrica!\n\n");
    exibe_simetrica(arv->raiz);
    printf("\n============\n\n");
    
    printf("\nPrint da forma pre-ordem!\n\n");
    exibe_preordem(arv->raiz);
    printf("\n============\n\n");

    

    return 0;
}


Arvore* criaArv()
{
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    if(arvore == NULL){
        printf("Erro ao aolcar memoria para a arvore");
        return 0;  
    } 

    arvore->raiz = NULL;
    return arvore;
}

void readArq(char* nome, int* vetor)
{
    FILE* arqEntrada = fopen(nome, "r");
    if(!arqEntrada)
    {
        printf("Erro ao abrir o arquivo de entrada");
        exit(1);
    }


    for(int i = 0; i < qtdChaves; i++)
    {
        fscanf(arqEntrada, " %d", &vetor[i]);
    }

    fclose(arqEntrada);
}

No* insere(Arvore* arv, int chave) //Começa a verificar a cada interação do início da árvore. (Raiz)
{

    Arvore* aux = arv;

    if(arv->raiz == NULL)
    {
        No* no = (No*)malloc(sizeof(No));
        if(!no)
        {
            printf("Erro ao aolcar memória para o nó inicial");
            exit(1);
        }

        no->chave=chave;
        no->dir = NULL;
        no->esq = NULL;

        arv->raiz = no;

        return arv->raiz;
    }


    No *p = arv->raiz;
    No* pai;// Serve para não perder a referência da cabeça anteriror


    while(p!=NULL)
    {
        pai = p;
        if(chave < p->chave)
            p = p->esq;
        else if(chave > p->chave)
            p = p->dir;
        else
            return p;
    }


    No* no = (No*)malloc(sizeof(No));
    if(!no)
    {
        printf("Erro ao alocar no linha 123");
        return NULL;
    }

    no->chave = chave;
    no->dir = NULL;
    no->esq = NULL;

    //O pai é o a cabeça do anterior depois que você achou o último para colocar.
    if (chave < pai->chave)
        pai->esq = no;
    else 
        pai->dir = no;

    p = no;
    return no;
}

void exibe_simetrica(No *p) {
    if (p == NULL)
        printf("arvore nao foi criada\n");
    if (p->esq != NULL)
        exibe_simetrica(p->esq);
    printf(/*"ptr_no=%p,*/ "%d " /*esq=%p dir=%p\n"*/, /*p,*/ p->chave /*p->esq, p->dir*/);
    if (p->dir != NULL)
        exibe_simetrica(p->dir);
}

void exibe_preordem(No *p) {
    if (p == NULL)
        printf("arvore nao foi criada\n");
    printf(/*"ptr_no=%p,*/ "%d " /*esq=%p dir=%p\n"*/, /*p,*/ p->chave /*p->esq, p->dir*/);
    if (p->esq != NULL)
        exibe_preordem(p->esq);
    if (p->dir != NULL)
        exibe_preordem(p->dir);
}


void exibe_por_nivel(No *raiz) {
    if (!raiz) return;

    No* vetorFila[qtdChaves];
    int inicio = 0;
    int fim = 0;

    vetorFila[fim] = raiz;
    fim++;//O fim não é mais esse pois entrou uma pessoa na fila que foi a raiz

    int nivel = 0;
    while (inicio < fim)
    {
        int n = fim - inicio; //"Fotografia" do tamnho da fila exemplo se o iníco é a casa 1 e o 3 é o fim o tamanho são 2.

        for(int i = 0; i<n; i++) //for que gira  a quantidade de elementos na fila, ou seja, da primeira posição atual da fila até a ultima posição atual da fila
        {
            No* p = vetorFila[inicio]; //Pega o nó da raiz na interação de início, é o comando que pega o próximo da fila
            inicio++; //incementa início pois depois que eu pegar o número, ele não é mais o inicial, ou seja anda a fila
            printf("%d ", p->chave);
            if(p->esq)//Verifica filho esquerdo
            {
                vetorFila[fim++] = p->esq;
                //fim++;
            }
            if (p->dir)//Verifica filho direito
            {
                vetorFila[fim++] = p->dir;
                //fim++;
            }
        }
        printf("(%d)  ", nivel);
        nivel++;
    }
    

}