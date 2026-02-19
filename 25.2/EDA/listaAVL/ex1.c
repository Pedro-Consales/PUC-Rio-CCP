#include <stdio.h>
#include <stdlib.h>


struct nodo {
    int chave;
    int h;
    struct nodo*esq;
    struct nodo*dir;
};
typedef struct nodo No;


int altura(No* no)
{
    return no ? no->h : -1; 
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int getBalance(No* no)
{
    if(no == NULL)
        return 0;
    return altura(no->esq) - altura(no->dir);
}

No* rotateRight(No* node)
{
    No *no_esq = node->esq;
    No *no_esq_dir = no_esq->dir;

    no_esq->dir = node;
    node->esq = no_esq_dir;

    node->h = max(altura(node->esq),
    altura(node->dir)) + 1;
    no_esq->h = max(altura(no_esq->esq),
        altura(no_esq->dir)) + 1;

    // Return new root
    return no_esq;
}

No* rotateLeft(No* node)
{
    No *no_dir = node->dir;
    No *no_dir_esq = no_dir->esq;

    // Executa a rotação
    no_dir->esq = node;
    node->dir = no_dir_esq;

    // Atualiza alturas
    node->h = max(altura(node->esq),
                  altura(node->dir)) + 1;
    
    no_dir->h = max(altura(no_dir->esq),
                    altura(no_dir->dir)) + 1;

    return no_dir;  // ✅ Retorna a nova raiz
}


No* insertAVL(No* node, int chave)
{

    if (node == NULL)
    {
        No* novo_no = (No*)malloc(sizeof(No));
        if(novo_no == NULL)
        {
            printf("Erro ao alocar memoria para o novo nó");
            exit(1);
        }

        novo_no->chave = chave;
        novo_no->dir = NULL;
        novo_no->esq = NULL;
        novo_no->h = 0;

        return novo_no;
    }

    if(chave < node->chave)
    node->esq = insertAVL(node->esq, chave);
    else if(chave > node->chave)
        node->dir = insertAVL(node->dir, chave);
    else
        return node;

    
    node->h = 1 + max(altura(node->esq),
    altura(node->dir));


    int balance = getBalance(node);
    
    // LL
    if (balance > 1 && chave < node->esq->chave)
        return rotateRight(node);

    // RR
    if (balance < -1 && chave > node->dir->chave)
        return rotateLeft(node);

    // LR
    if (balance > 1 && chave > node->esq->chave) {
        node->esq = rotateLeft(node->esq);
        return rotateRight(node);
    }

    // RL
    if (balance < -1 && chave < node->dir->chave) {
        node->dir = rotateRight(node->dir);
        return rotateLeft(node);
    }


    return node;

}

void exibe_por_nivel(No *raiz) {
    if (!raiz) return;

    No* vetorFila[12];
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

void preOrder(No *root)
{
    if(root != NULL)
    {
        printf("%d ", root->chave);
        preOrder(root->esq);
        preOrder(root->dir);
    }
}   


int main(void)
{
    
    int listaChaves[] = {30, 50, 70, 60, 80, 40, 20, 10, 5, 35, 55, 1};

    No *raiz = NULL;

    for(int i = 0; i < 12; i++)
    {
        raiz = insertAVL(raiz, listaChaves[i]);
    }
    preOrder(raiz);

    printf("\n\n");

    exibe_por_nivel(raiz);

    return 0;
}