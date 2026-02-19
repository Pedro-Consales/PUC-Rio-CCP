#include<stdio.h>
#include<stdlib.h>
#include<string.h>




typedef struct lista Lista;
typedef struct elemento Elemento;

struct elemento
{
	int mat;
	Elemento* prox;
};

struct lista
{
	Elemento* prim;
};


int main(void)
{



}

Lista* criaLista(void)
{ 
	Lista* l = (Lista*)malloc(sizeof(Lista));
	if (l == NULL)
	{
		printf("Erro ao alocar memoria para lista");
		exit(1);
	}
	l->prim = NULL;
	
	return l;
}