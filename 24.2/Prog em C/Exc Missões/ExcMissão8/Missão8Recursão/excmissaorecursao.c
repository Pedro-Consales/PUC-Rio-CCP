// 1.Escreva as seguintes funções:

// - lst_cria

// - lst_insere

// - exibe_lista

// - conta_elementos_recursiva(), que recebe uma lista de alunos e retorna o número de alunos nessa lista.

// - conta_sexo_recursiva(), que recebe uma lista de alunos e um sexo, e retorna o numero de pessoas com esse sexo na lista.

// A seguir, algumas definições e implementações para você testar as funções desenvolvidas por você.

// 1.Escreva as seguintes funções:

// - lst_cria

// - lst_insere

// - exibe_lista

// - conta_elementos_recursiva(), que recebe uma lista de alunos e retorna o número de alunos nessa lista.

// - conta_sexo_recursiva(), que recebe uma lista de alunos e um sexo, e retorna o numero de pessoas com esse sexo na lista.

// A seguir, algumas definições e implementações para você testar as funções desenvolvidas por você.


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct aluno Aluno;
//
//struct aluno
//{
//
//    int mat;
//
//    char nome[21];
//
//    float nota;
//
//    char sexo;
//
//    Aluno* prox;
//
//};
//
//// CABEÇALHO----------------------------
//
//Aluno* lst_cria(void);
//Aluno* lst_insere(Aluno* lal, int mat, char* nome, float nota, char sexo);
//void exibe_lista(Aluno* lal);
//void lst_libera(Aluno* lst);
//int conta_elementos_recursiva(Aluno* lal);
//int conta_sexo_recursiva(Aluno* lal, char sexo);
//Aluno* quebraAoMeio(Aluno* lal);
//Aluno* fazCopia(Aluno* lal);
//int maiorMatricula(Aluno* lal);
//
//// CABEÇALHO----------------------------
//
//
//int main(void) {
//
//    char sex = 'M';
//
//    Aluno* lal;
//
//    lal = lst_cria();
//
//    lal = lst_insere(lal, 33, "Caio", 3.3, 'M');
//
//    lal = lst_insere(lal, 11, "Ana", 1.1, 'F');
//
//    lal = lst_insere(lal, 44, "Edu", 4.4, 'M');
//
//    lal = lst_insere(lal, 66, "Luiz", 6.6, 'M');
//
//    lal = lst_insere(lal, 22, "Bia", 2.2, 'F');
//
//    lal = lst_insere(lal, 55, "Jane", 5.5, 'F');
//
//    /* inserir aqui a chamada para as suas funções e testes */
//
//    exibe_lista(lal);
//
//    conta_elementos_recursiva(lal);
//
//    printf("\n\nA quantidade de alunos do sexo %c sao %d\n\n", sex, conta_sexo_recursiva(lal, sex));
//
//    exibe_lista(quebraAoMeio(lal));
//
//    printf("!!!!!!!!!!!\n\n");
//
//    exibe_lista(fazCopia(lal));
//
//    printf("\n\nA maior matricula eh: %d", maiorMatricula(lal));
//
//    lal = insereNaPosição(lal, 100, "Pedro", 10.0, 'M', 3);
//
//    exibe_lista(lal);
//
//    lst_libera(lal);
//
//
//    return 0;
//}
//
//
//
//
//Aluno* lst_cria(void) {
//
//    return NULL;
//}
//
//
//
//
//Aluno* lst_insere(Aluno* lal, int mat, char* nome, float nota, char sexo) {
//
//    Aluno* novo;
//
//    novo = (Aluno*)malloc(sizeof(Aluno));
//
//    if (novo == NULL)
//    {
//
//        return NULL;
//    }
//
//    novo->mat = mat;
//    strcpy(novo->nome, nome);
//    novo->nota = nota;
//    novo->sexo = sexo;
//    novo->prox = lal;
//
//    return novo;
//}
//
//
//
//void exibe_lista(Aluno* lal) {
//
//    Aluno* p;
//
//    for (p = lal; p != NULL; p = p->prox)
//    {
//
//        printf("|| Matricula: %d / Nome: %s / Nota: %.2f / Sexo: %c ||\n\n", p->mat, p->nome, p->nota, p->sexo);
//    }
//    return;
//}
//
//
//
//void lst_libera(Aluno* lst) {
//
//    Aluno* p = lst, * t;
//
//    while (p != NULL)
//
//    {
//
//        t = p->prox; /* guarda referência p/ próx. Aluno */
//
//        free(p); /* libera a memória apontada por p */
//
//        p = t; /* faz p apontar para o próximo */
//    }
//}
//
//
//int conta_elementos_recursiva(Aluno* lal) {
//
//    int somaQtdAlunos = 0;
//
//    if (lal == NULL) {
//
//        return 0;
//
//    }
//
//    somaQtdAlunos += 1;
//
//    somaQtdAlunos += conta_elementos_recursiva(lal->prox);
//
//    return somaQtdAlunos;
//
//}
//
//int conta_sexo_recursiva(Aluno* lal, char sex) {
//
//    int contaQtdSexo = 0;
//    //Aluno *p;
//
//    if (lal == NULL) {
//
//        return 0;
//
//    }
//    if (lal->sexo == sex) {
//
//        contaQtdSexo += 1;
//        contaQtdSexo += conta_sexo_recursiva(lal->prox, sex);
//
//        return contaQtdSexo;
//    }
//    else {
//
//        return conta_sexo_recursiva(lal->prox, sex);
//
//    }
//
//
//}
//
//
//Aluno* quebraAoMeio(Aluno* lal) {
//
//    int totAlunos = conta_elementos_recursiva(lal);
//    int meio;
//
//    if (totAlunos < 2) {
//
//        return NULL;
//
//    }
//    if (totAlunos % 2 == 0) {
//        meio = totAlunos / 2;
//    }
//    else {
//        meio = (totAlunos / 2) + 1;
//    }
//
//    Aluno* p = lal;
//    for (int i = 0; i < meio; i++) {
//
//        p = p->prox;
//
//    }
//    return p;
//}
//
//
//Aluno* fazCopia(Aluno* lal) {
//    if (lal == NULL) {
//
//        return NULL;
//
//    }
//
//    Aluno* nvLista = (Aluno*)malloc(sizeof(Aluno));
//    //nvLista->mat = lal->mat;
//
//    nvLista->mat = lal->mat;
//    strcpy(nvLista->nome, lal->nome);
//    nvLista->nota = lal->nota;
//    nvLista->sexo = lal->sexo;
//    nvLista->prox = fazCopia(lal->prox);
//
//    return nvLista;
//}
//
//// Assumindo que a lista não está ordenada, escreva a função RECURSIVA maiorMatricula que recebe a lista (ou seja, o ponteiro para o primeiro elemento da lista) 
//// e retorna a maior matrícula (ou seja, a matrícula de maior valor). Caso não exista nenhum pedido a função retorna -1. Exemplo: para uma lista de pedidos como a 
//// da Figura 2, a função retorna o valor 415. 
//
//
//int maiorMatricula(Aluno* lal) {
//
//    if (lal == NULL) {
//
//        return 0;
//    }
//    if (lal->mat > maiorMatricula(lal->prox)) {
//
//        return lal->mat;
//
//    }
//}
//
//// Escreva a função insereNaPosicao que: 
//
//// - recebe (o endereço do primeiro nó de) uma lista simplesmente encadeada, um valor a ser inserido na lista, e a posição k (k >= 1) 
//// na lista onde deve ser feita a inserção 
//
//// - faz a inserção de novo nó na lista, retornando a lista atualizada (o endereço do primeiro nó). O novo nó deve ser inserido como o
////  k-ésimo elemento da lista. Caso isso não seja possível, ou seja, não exista k-1 elementos na lista, ele deve ser inserido como último da lista. 
////  Se houver falta de memória a lista permanece como está e uma mensagem apropriada é exibida. 
//
//// Obs: a lista pode ter repetição de valores. 
//
//Aluno* insereNaPosição(Aluno* lal, int mat, char* nome, float nota, char sexo, int pos) {
//
//    Aluno* temp = lal;
//
//    Aluno* novo;
//
//    novo = (Aluno*)malloc(sizeof(Aluno));
//
//    if (novo == NULL) {
//
//        return NULL;
//    }
//
//    novo->mat = mat;
//    strcpy(novo->nome, nome);
//    novo->nota = nota;
//    novo->sexo = sexo;
//
//    for (int i = 0; i < pos - 1; i++) {
//
//        temp = temp->prox;
//
//    }
//
//    novo->prox = temp->prox->prox;
//    temp->prox = novo;
//    return lal;
//
//
//}

//=================================================================================================================================================================
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define ALPHA 26
//
//
//
//struct clist
//{
//
//    char* nome;
//    int id;
//    float rating;
//    struct clist* prox;
//
//};
//
//
//typedef struct cadastro Cadastro;
//
//
//struct cadastro
//{
//    struct clist* lCad[ALPHA];
//};
//
//
//
////Cabeçalho========================================
//
//Cadastro* criaCadastro(void);
//int insere(Cadastro* cadastro, char* Nome, int Id, float Rating);
//void exibeCadastro(Cadastro* cadastro);
//float averageRating(Cadastro* cadastro);
//void liberaMemoria(Cadastro* cadastro);
//
////Cabeçalho========================================
//
//
//int main(void) {
//
//    Cadastro* cadastro;
//
//    cadastro = criaCadastro();
//
//    insere(cadastro, "Ahsoka", 105, 5.0);
//    insere(cadastro, "Ada Lovelace", 103, 4.5);
//    //insere(cadastro, "Bruno Monitor(em homenagem!)", 2212576, 10.00);
//    insere(cadastro, "Fani", 106, 4.0);
//    insere(cadastro, "Fred", 104, 3.0);
//    insere(cadastro, "Fiona", 101, 2.0);
//    insere(cadastro, "Zelda", 102, 5.0);
//
//    exibeCadastro(cadastro);
//
//    printf("\nAverage Rating: %.2f\n", averageRating(cadastro));
//
//    liberaMemoria(cadastro);
//
//    return 0;
//}
//
//
////Funções==========================================
//
//Cadastro* criaCadastro(void) {
//
//    int i;
//
//    Cadastro* cadastro = (Cadastro*)malloc(sizeof(Cadastro));
//    if (cadastro == NULL) {
//        printf("Erro ao alocar memória para cadastro.\n");
//        exit(1);
//    }
//
//    for (i = 0; i < ALPHA; i++) {
//        cadastro->lCad[i] = NULL;
//    }
//
//    return cadastro;
//}
//
//
//int insere(Cadastro* cadastro, char* Nome, int Id, float Rating) { //Entender a lógica dessa função;
//
//    int i;
//
//    for (i = 0; i < ALPHA; i++) {
//        if (Nome[0] == i + 65) {
//            struct clist* novo = (struct clist*)malloc(sizeof(struct clist));
//            if (novo == NULL) {
//
//                printf("Erro ao alocar memoria na funao insere para a variavel novo");
//                exit(1);
//            }
//
//            novo->id = Id;
//            novo->rating = Rating;
//
//            novo->nome = (char*)malloc((strlen(Nome) + 1) * sizeof(char));
//            if (novo->nome == NULL) {
//
//                printf("Erro ao alocar memoria na funcao insere para a string nome");
//                exit(1);
//            }
//            strcpy(novo->nome, Nome);
//
//            novo->prox = cadastro->lCad[i];
//            cadastro->lCad[i] = novo;
//            printf("Cadastrado com sucesso!\n");
//            return 1;
//        }
//    }
//    return 0;
//}
//
//void exibeCadastro(Cadastro* cadastro) {
//
//    int i;
//    int c = 65;
//    printf("Lista de cadastro:\n");
//    for (i = 0; i < ALPHA; i++) {
//
//        printf(" %c: \n", c);
//        struct clist* p = cadastro->lCad[i];
//        while (p != NULL) {// Por que precisa ter esse null;
//            printf("    %s: %d %.2f\n", p->nome, p->id, p->rating);
//            p = p->prox;
//        }
//        c++;
//    }
//    return;
//}
//
//float averageRating(Cadastro* cadastro) {
//
//    int i;
//    float soma;
//    float media;
//    int qtdCadastros;
//
//    qtdCadastros = 0;
//    soma = 0.0;
//
//    for (i = 0; i < ALPHA; i++) {
//
//        struct clist* p = cadastro->lCad[i];
//        while (p != NULL) { //Por que precisa ter esse NULL???;
//
//            soma = soma + p->rating;
//            qtdCadastros++;
//            p = p->prox;
//        }
//    }
//
//    media = soma / qtdCadastros;
//
//    return media;
//}
//
//void liberaMemoria(Cadastro* cadastro) {
//
//    int i;
//    struct clist* p;
//    struct clist* anterior;
//    for (i = 0;i < ALPHA;i++) {
//        p = cadastro->lCad[i];
//        if (cadastro->lCad[i] != NULL) {
//
//            while (p->prox != NULL) {
//
//                anterior = p;
//                p = p->prox;
//                free(anterior);
//
//            }
//            free(p);
//        }
//    }
//    free(cadastro->lCad);
//
//    return;
//}

//================================================================================================================================================================

// [1] Defina o tipo estruturado Aresta que contém o vértice início e o vértice fim 
// de uma aresta. Usando este tipo, defina o grafo da Fig.1 como sendo um vetor 
// de arestas alocado estaticamente, e.g. Aresta conjArestas1[] = { {0,1}, … };


// [2] Defina o tipo estruturado Grafo (que contém um vetor estático de ponteiros 
// para Node)1 e escreva a função createGraph para criar e inicializar o grafo com 
// um vetor de ponteiros para NULL. Essa função recebe o número de vértices e 
// retorna um ponteiro para Grafo. 


//#include <stdio.h>
//#include <stdlib.h>
//#define QTDARESTAS 6
//#define QTDVERTICIES 5
//
//
//
//
//typedef struct aresta Aresta;
//struct aresta
//{
//    int VerticieI;
//    int VetricieF;
//};
//
//typedef struct node Node;
//struct node
//{
//    int verticiePontaFinal;
//    Node* prox;
//};
//
//
//typedef struct grafo Grafo;
//struct grafo
//{
//    Node* lAdj[5];
//};
//
//
////Cabeçalho==========================
//
//Grafo* createGraph(int qtdVerticies);
//Node* insertNode(Node* head, int endVertex);
//Grafo* setGraph(Grafo* grafo, Aresta conjarestas[], int tamVetor);
//void printGraph(Grafo* grafo);
//
////Cabeçalho==========================
//
//
//int main(void) {
//
//
//    Grafo* grafo;
//
//    Aresta conjArestas1[QTDARESTAS] = { {0,1}, {1,2},{2,0},{2,1}, {3,1}, {4,2} };
//
//    grafo = createGraph(QTDVERTICIES);
//    grafo = setGraph(grafo, conjArestas1, QTDARESTAS);
//    printGraph(grafo);
//
//
//
//}
//
//// escreva a função createGraph para criar e inicializar o grafo com 
//// um vetor de ponteiros para NULL. Essa função recebe o número de vértices e 
//// retorna um ponteiro para Grafo. 
//
//Grafo* createGraph(int qtdVerticies) {
//
//
//    int i;
//
//    Grafo* p = (Grafo*)malloc(sizeof(Grafo));
//    if (p == NULL) {
//
//        printf("Erro ao alocar memoria para a lista com node\n");
//
//    }
//
//    for (i = 0; i < qtdVerticies; i++) {
//
//        p->lAdj[i] = NULL;
//
//    }
//
//    return p;
//}
//
//Node* insertNode(Node* head, int endVertex) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->verticiePontaFinal = endVertex;
//    newNode->prox = head;
//
//    return newNode;
//}
//
//Grafo* setGraph(Grafo* grafo, Aresta conjarestas[], int tamVetor) {
//
//    int i;
//    for (i = 0;i < tamVetor;i++) {
//        int inicio = conjarestas[i].VerticieI;
//        grafo->lAdj[inicio] = insertNode(grafo->lAdj[inicio], conjarestas[i].VetricieF);
//
//    }
//
//    return grafo;
//}
//
//
//void printGraph(Grafo* grafo) {
//
//    for (int i = 0; i < QTDVERTICIES; i++) {
//
//        Node* atual = grafo->lAdj[i];
//        while (atual != NULL) {
//            printf("(%d -> %d)  ", i, atual->verticiePontaFinal);
//            atual = atual->prox;
//        }
//
//    }
//
//}

// 6] Escreva a função isEdge que testa se dois vértices dados são uma aresta do grafo dirigido. Essa função recebe um ponteiro 
// para Grafo e os dois vértices (como números inteiros) e retorna verdadeiro ou falso. Por exemplo, na Fig. 1, 2 -> 0 formam 
// uma aresta, mas 2 -> 4 não. 

// int isEdge(Grafo* grafo, int verticie1, int verticie2){

//     int Falso = 1;
//     int Verdadeiro = 2;
//     int i;

//     for(i=0;i<QTDVERTICIES;i++){

//         Node* atual = grafo->lAdj[i];
//         if (i)
//         {
//             /* code */
//         }



//     }





// }

//FODASE



//=================================================================================================================================================================

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define ALPHA 26
//
//typedef struct node Node;
//struct node
//{
//
//	char* nome;
//	int tel;
//	Node* prox;
//
//};
//
//
//struct agenda
//{
//
//	Node* lNode[ALPHA];
//
//
//};
//typedef struct agenda Agenda;
//
//
////Cabeçalho========
//
//Agenda* criaAgenda(void);
//Node* insereNode(Node* head, char* nome, int tel);
//int inserePessoa(Agenda* a, char* nome, int tel);
//void exibeAgenda(Agenda* a, char letra);
//
////Cabeçalho========
//
//int main(void) {
//
//	Agenda* l;
//	int i;
//
//	l = criaAgenda();
//
//	i = inserePessoa(l, "Pedro", 123);
//	i = inserePessoa(l, "Ana", 456);
//	i = inserePessoa(l, "Gugu", 789);
//	i = inserePessoa(l, "Barba", 741);
//
//	exibeAgenda(l, 'P');
//	exibeAgenda(l, 'A');
//
//}
//
////Funções=========
//
//Agenda* criaAgenda(void) {
//
//	int i;
//
//	Agenda* agenda = (Agenda*)malloc(sizeof(Agenda));
//	if (agenda == NULL) {
//
//		return NULL;
//
//	}
//
//	for (i = 0; i < ALPHA; i++) {
//
//		agenda->lNode[i] = NULL;
//
//	}
//
//	return agenda;
//}
//
//Node* insereNode(Node* head, char* nome, int tel) {
//
//	Node* p = (Node*)malloc(sizeof(Node));
//	if (p == NULL) {
//
//		return NULL;
//
//	}
//
//	p->nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));
//	if (p->nome == NULL) {
//
//		free(p);
//		return NULL;
//
//	}
//	strcpy(p->nome, nome);
//
//	p->tel = tel;
//	p->prox = head;
//
//	return p;
//}
//
//int inserePessoa(Agenda* a, char* nome, int tel) {
//
//
//	Node* p = NULL;
//
//	int index = nome[0] - 'A';
//
//	p = insereNode(a->lNode[index], nome, tel);
//
//	if (p == NULL) {
//
//		return 0;
//	}
//	a->lNode[index] = p;
//	return 1;
//}
//
//void exibeAgenda(Agenda* a, char letra) {
//
//	Node* p;
//	int i = letra - 'A';
//
//	p = a->lNode[i];
//	printf("%c:\n", letra);
//	while (p != NULL) {
//
//		printf(" %s: %d\n", p->nome, p->tel);
//		p = p->prox;
//	}
//	return;
//}

//=======

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
    Elemento* prox;

};

typedef struct elemento Elemento;


//#Cabeçalho======================

Elemento* insereFimRec(Elemento* head, int valor, int linha, int coluna);
Elemento* montaLista(int* dim);
void imprimeMatriz(Elemento* head, int dim);

//#Cabeçalho======================

int main(void) {

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

Elemento* insereFimRec(Elemento* head, int valor, int linha, int coluna) {

    if (head == NULL) {
        Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
        if (novo = NULL) {

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

Elemento* montaLista(int* dim) {

    FILE* arqEntrada;

    arqEntrada = fopen("Matriz4x4.txt", "r");

    if (fscanf(arqEntrada, "%d", dim) != 1) {

        printf("Erro ao obter a dimensao");
        fclose(arqEntrada);
        return NULL;
    }

    Elemento* lst = NULL;

    int n = *dim;
    int i;
    int j;
    int bufferValor;
    for (i = 0; i < n; i++) {

        for (j = 0; j < n; j++) {

            if (fscanf(arqEntrada, "%d", &bufferValor) != 1 && bufferValor != 0) {
                lst = insereFimRec(lst, bufferValor, i, j);
                if (lst == NULL) {
                    fclose(arqEntrada);
                    return NULL;
                }

            }

        }


    }

    fclose(arqEntrada);
    return lst;

}

void imprimeMatriz(Elemento* head, int dim) {

    int i;
    int j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {

            if (head != NULL, head->info.plinha == i, head->info.pcoluna == j) {

                printf("%d", head->info.valor);
                head = head->prox;
            }
            else {

                printf("%d", 0);

            }

        }

        printf("\n");

    }

}