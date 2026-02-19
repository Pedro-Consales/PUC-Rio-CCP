#include<stdio.h>
#include<stdlib.h>

struct matrizElemento
{
    int valor;
    int plinha;
    int pcoluna;

};

typedef struct matrizElemento MatrixElem;


struct elemento
{

    MatrixElem info;
    Elemento * prox;

};

typedef struct elemento Elemento;


//#Cabeçalho======================

Elemento* insereFimRec(Elemento* head, int valor, int linha, int coluna);
Elemento* montaLista(int *dim);
void imprimeMatriz(Elemento* head, int dim);

//#Cabeçalho======================

int main(void){

    int dim;
    Elemento* head = NULL;
    head = montaLista(&dim);

    if (head == NULL) {
        printf("Erro de alocacao de memoria!");
        exit(1);
    }
    imprimeMatriz(head, dim);
    // gravaBin(head, dim);


    //FCLOSES POR FAVOR
    // NAO ESQUECER ED DAR CLOSE E FREE
    return 0;

}

Elemento* insereFimRec(Elemento* head, int valor, int linha, int coluna){

    if(head == NULL){
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if(novo = NULL){

            return NULL;

        }

        novo->info.valor = valor;
        novo->info.plinha = linha;
        novo->info.pcoluna = coluna;
        novo->prox = NULL;

        return novo;
    }
    
    head->prox = insereFimRec(head->prox, valor, linha, coluna);
    return head;

}

Elemento* montaLista(int *dim){

    FILE * arqEntrada;

    arqEntrada = fopen("Matriz4x4.txt", "r");

    if(fscanf(arqEntrada, "%d", dim)!=1){

        printf("Erro ao obter a dimensao");
        fclose(arqEntrada);
        return NULL;
    }

    Elemento *lst = NULL;

    int n = *dim;
    int i;
    int j;
    int bufferValor;
    for(i=0; i<n; i++){
        
        for(j=0; j<n; j++){

            if(fscanf(arqEntrada, "%d", &bufferValor)!=1 && bufferValor != 0){
                lst = insereFimRec(lst, bufferValor, i, j);
                if(lst==NULL){
                    fclose(arqEntrada);
                    return NULL;
                }

            }

        }


    }
    
    fclose(arqEntrada);
    return lst;

}

void imprimeMatriz(Elemento* head, int dim){

    int i;
    int j;

    for(i=0; i<dim; i++){
        for(j=0; j<dim; j++){

            if(head != NULL, head->info.plinha == i, head->info.pcoluna == j){

                printf("%d", head->info.valor);
                head = head->prox;
            }
            else{

                printf("%d", 0);

            }

        }

        printf("\n");

    }

}