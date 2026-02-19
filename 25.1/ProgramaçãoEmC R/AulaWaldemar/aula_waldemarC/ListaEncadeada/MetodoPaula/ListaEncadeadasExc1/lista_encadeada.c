#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct informacao Info;
struct informacao
{
	int  codigo;
	char nome[31];
};

typedef struct no No;
struct no
{
	Info* info;
	No* prox;
};

void insere(No** l, int cod, char* nome);
void exibe(No* l);

int main(void)
{
	No* l = NULL; 

	insere(&l, 84, "A60");
	insere(&l, 31, "B10");
	insere(&l, 45, "A50");
	insere(&l, 36, "A20");
	insere(&l, 22, "A30");

	exibe(l);

	return 0;
}

void insere(No** l, int cod, char* nome)
{
	No* n = (No*)malloc(sizeof(No));
	n->info = (Info*)malloc(sizeof(Info));

	n->info->codigo = cod;
	strcpy(n->info->nome, nome);

	/*n->prox = *l; (insere no início da lista, fora de ordem de chamadas da função insere)
	*l = n;*/

	n->prox = NULL;
	if (*l == NULL)  // ✅ CORRIGIDO AQUI (Insere no final da lista, na ordem de chamada das funções insere)
	{
		*l = n;
	}
	else
	{
		No* p = *l;
		while (p->prox != NULL)
			p = p->prox;

		p->prox = n;
	}
}

void exibe(No* l)
{
	No* p = l;
	int cont = 1;

	while (p != NULL)  // ✅ CORRIGIDO AQUI
	{
		printf("Elemento: %d\n", cont);
		printf("Codigo: %d\n", p->info->codigo);
		printf("Nome: %s\n\n", p->info->nome);

		p = p->prox;
		cont++;
	}
}
