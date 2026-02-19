#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct pedido Pedido;
struct pedido
{
	int matricula;	/* matricula do aluno que solicita a bolsa */
	char tipoDoPedido[21];	/* “soc”, “ic”, “mest”, “dout” */
	Pedido* prox;	/* ponteiro para o proximo pedido */
};

typedef struct lista Lista;
struct lista
{
	Pedido* prim;
};

Lista* cria();
void insere(Lista* l, int matricula, char* tipoDoPedido);
void exibe(Lista* l);
int maiorMatricula_rec(Pedido* p);
int maiorMat_NaoRec(Lista* l);

int main(void)
{
	Lista* lista = cria();

	insere(lista, 203, "ic");
	insere(lista, 205, "ic");
	insere(lista, 101, "soc");
	insere(lista, 415, "dout");
	insere(lista, 201, "ic");

	exibe(lista);

	int maior = maiorMatricula_rec(lista->prim);

	printf("O maior matricula por recursiva eh %d\n\n", maior);

	maior = maiorMat_NaoRec(lista);
	
	printf("O maior matricula NAO recursiva eh %d", maior);
	

	return 0;
}


Lista* cria()
{
	Lista* l = (Lista*)malloc(sizeof(Lista));
	if (l == NULL)
	{
		printf("Erro ao aolcar memoria para o l");
		exit(1);
	}
	l->prim = NULL;

	return l;
}

void insere(Lista* l, int matricula, char* tipoDoPedido)
{
	Pedido* p = (Pedido*)malloc(sizeof(Pedido));

	p->matricula = matricula;
	strcpy(p->tipoDoPedido, tipoDoPedido);
	
	p->prox = NULL;

	if (l->prim == NULL)
		l->prim = p;

	else
	{
		Pedido* n = l->prim;
		while (n->prox != NULL)
			n = n->prox;

		n->prox = p;
	}
}

void exibe(Lista* l)
{
	Pedido* p = l->prim;

	int cont = 1;
	while (p != NULL)
	{
		printf("Elemento %d\n\n", cont);
		printf("Matricula: %d\n", p->matricula);
		printf("Tipo: %s\n", p->tipoDoPedido);
		printf("\n\n======\n\n");
		p = p->prox;
		cont++;
	}
}

int maiorMatricula_rec(Pedido* p)
{
	if (p == NULL)
	{
		return -1;
	}

	if (p->prox == NULL)
	{
		return p->matricula;
	}
	else
	{
		int maior = maiorMatricula_rec(p->prox);
		
		if (maior < p->matricula)
		{
			return p->matricula;
		}
		else
		{
			return maior;
		}
	
	}
}

int maiorMat_NaoRec(Lista* l)
{
	Pedido* p = l->prim;
	int maior = l->prim->matricula;

	while (p != NULL)
	{
		if (maior < p->matricula)
		{
			maior = p->matricula;
		}
		p = p->prox;
	}
	
	return maior;
}