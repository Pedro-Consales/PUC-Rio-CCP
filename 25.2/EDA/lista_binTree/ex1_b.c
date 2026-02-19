// Escrever algoritmo para criar uma árvore binária e inserir nó na árvore (sempre completa
//     ou cheia).
//     a. A partir de números gerados aleatoriamente.
//     b. A partir de um vetor previamente inicializado (neste caso para testes não precisa ser
//     completa ou cheia).



#include <stdio.h>
#include <stdlib.h>



typedef struct no No    ;

typedef struct tree Tree;

struct no
{
    int num;
    No* dir;
    No* esq;
};

struct tree
{
    No* raiz;
};


Tree *criaArvore();
No* insereNo(Tree* arv, int num);

int main(void)
{

    int vetor[6] = {8, 3, 10, 1, 6, 14};
    Tree* arv = criaArvore();
    for(int i = 0; i < 6; i++)
    {
        int num_atual = vetor[i];
        insereNo(arv, num_atual);
    }
    


    return 0;
}

Tree* criaArvore()
{
    Tree* arv = (Tree*)malloc(sizeof(Tree));
    arv->raiz = NULL;
    return arv;
}

No* insereNo(Tree* arv, int num)
{
    if(arv->raiz == NULL)
    {
        No* no = (No*)malloc(sizeof(No));
        no->num = num;
        no->dir = NULL;
        no->esq = NULL;

        arv->raiz = no;
        return;
    }

    No *p = arv->raiz;

    No *pai = NULL;
    while (p != NULL) {
        pai = p;
        if (num < p->num)      
            p = p->esq;
        else if (num > p->num)
            p = p->dir;
        else return p;
    }

    No* no = (No*)malloc(sizeof(No));
    no->num = num;
    no->esq = NULL; 
    no->dir = NULL;

    if (num < pai->num) 
        pai->esq = no;
    else                
        pai->dir = no;

    return no;

}


