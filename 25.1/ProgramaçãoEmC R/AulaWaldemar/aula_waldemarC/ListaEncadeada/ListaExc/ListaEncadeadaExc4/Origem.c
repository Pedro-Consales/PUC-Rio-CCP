#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct elemento Elemento;
struct elemento
{
	int codigo;
	char nome[51];
	Elemento* prox;
};
typedef struct lista Lista;
struct lista
{
	Elemento* prim;
};

Lista* cria();
void insere(Lista* l, int cod, char* nome);
void exibe(Lista* l);

int main(void)
{

	Lista* l = cria();

	insere(l ,10, "Pedro");

	exibe(l);

	return 0;
}

Lista* cria()
{
	Lista* l = (Lista*)malloc(sizeof(Lista));
	if (l == NULL)
	{
		printf("Erro ao alocar memoria para a lista");
		exit(1);
	}
	l->prim = NULL;

	return l;
}

void insere(Lista* l, int cod, char* nome)
{
	Elemento* e = (Elemento*)malloc(sizeof(Elemento));
	if (e == NULL)
	{
		printf("Erro ao alocar memoria para elemento");
		exit(1);
	}

	e->codigo = cod;
	strcpy(e->nome, nome);

	e->prox = NULL;

	Elemento* p;
	if (l->prim == NULL)
	{
		l->prim = e;
	}
	else
	{
		Elemento* ele;
		ele = l->prim;
		while (ele->prox != NULL)
		{
			ele = ele->prox;
		}
		ele->prox = e;
	}

}

void exibe(Lista* l)
{
	Elemento* p = l->prim;
	int cont = 1;
	while (p != NULL)
	{
		printf("Elemento %d\n\n", cont);
		printf("Codigo: %d\n", p->codigo);
		printf("Nome: %s\n", p->nome);
		
		printf("\n\n====\n\n");

		p = p->prox;
	}



}

//Se o codAtual é maior que o atual e menor do que o proximo ele entra no meio
//Se não anda pra frente

Lista* MergeListas(Lista* l1, Lista* l2)
{
	Elemento* p1;
	Elemento* p2;
	Lista* nv_lista = cria();
	Elemento* novaL = nv_lista->prim;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->codigo == p2->codigo)
		{
			novaL = p1;
			novaL->prox = NULL;
			Elemento* temp = p2;
			l2->prim = p2->prox;
			free(temp);
			l1->prim = p1->prox;
		}
		else if (p1->codigo > p2->codigo)
		{
			nv
		}
		
		p1 = l1->prim;
		p2 = l2->prim;
	}

	


}