//Pedro Consles Margaronis - 2410238
//Gabriel de Castro Fontes - 2421177

#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define MIN 2

typedef struct no t_no; 
struct no
{
    int ndesc;
    int chave[MAX];
    t_no *ramo[MAX+1];
};

void intervalo(t_no *arv, int lim_inf, int lim_sup) {
    if (arv == NULL) return;

    // para cada chave da página
    for (int i = 0; i < arv->ndesc; i++) {
        //primeiro desce na sub-árvore da esquerda daquela chave
        intervalo(arv->ramo[i], lim_inf, lim_sup);

        int x = arv->chave[i];
        if (lim_inf < x && x < lim_sup) {
            printf("%d ", x);
        }
    }

    //visita a sub-árvore à direita da última chave
    intervalo(arv->ramo[arv->ndesc], lim_inf, lim_sup);
}

int main() {

    t_no *raiz = malloc(sizeof(t_no));
    raiz->ndesc = 1;
    raiz->chave[0] = 100;




    
    /* "lado esquerdo" da raiz (valores < 100) */
    raiz->ramo[0] = malloc(sizeof(t_no));
    t_no *esq = raiz->ramo[0]; //esq é o filho da esqueda da raiz
    esq->ndesc = 2;
    esq->chave[0] = 50;
    esq->chave[1] = 75;

    t_no *folha1 = malloc(sizeof(t_no)); //Folha 1 no ramo[0] do esq(filho a esq)
    folha1->ndesc = 2; // folha
    esq->ramo[0] = folha1;
    folha1->chave[0] = 10;
    folha1->chave[1] = 40;

    t_no *folha2 = malloc(sizeof(t_no)); //Folha 2 no ramo[1] do esq(filho a esq)
    folha2->ndesc = 2; // folha
    esq->ramo[1] = folha2;
    folha2->chave[0] = 60;
    folha2->chave[1] = 70;

    t_no *folha3 = malloc(sizeof(t_no)); //Folha 3 no ramo[2] do esq(filho a esq)
    folha3->ndesc = 2; // folha
    esq->ramo[2] = folha3;
    folha3->chave[0] = 80;
    folha3->chave[1] = 90;
    

    /* "lado direito" da raiz (valores > 100) */
    raiz->ramo[1] = malloc(sizeof(t_no));
    t_no *dir = raiz->ramo[1]; //Dir é o filho à direita da raiz.
    dir->ndesc = 2;
    dir->chave[0] = 120;
    dir->chave[1] = 200;

    t_no *folha4 = malloc(sizeof(t_no)); //Folha 4 no ramo[0] do dir(filho a direita)
    dir->ramo[0] = folha4;
    folha4->ndesc = 2;
    folha4->chave[0] = 110;
    folha4->chave[1] = 115;

    t_no *folha5 = malloc(sizeof(t_no)); //Folha 5 no ramo[1] do dir(filho a direita)
    dir->ramo[1] = folha5;
    folha5->ndesc = 4;
    folha5->chave[0] = 130;
    folha5->chave[1] = 135;
    folha5->chave[2] = 140;
    folha5->chave[3] = 170;

    t_no *folha6 = malloc(sizeof(t_no)); //Folha 5 no ramo[2] do dir(filho a direita)
    folha6->ndesc = 4;
    dir->ramo[2] = folha6;
    folha6->chave[0] = 220;
    folha6->chave[1] = 230;
    folha6->chave[2] = 240;
    folha6->chave[3] = 250;

    intervalo(raiz, 0, 260); //Fiz nesses valores para incluir as chaves.

    return 0;
}