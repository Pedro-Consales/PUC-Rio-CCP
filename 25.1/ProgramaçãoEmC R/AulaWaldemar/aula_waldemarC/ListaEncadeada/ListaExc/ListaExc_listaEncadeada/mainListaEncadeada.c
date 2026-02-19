#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
typedef struct lista Lista;
struct lista
{
	No* prim;

};
Lista* cria();
void insere(Lista* prim, int cod, char* nome);
void exibe(No* l);
Lista* quebraAoMeio(Lista* l);

int main(void)
{
	Lista* l = cria();


	insere(l, 84, "A60");
	insere(l, 31, "B10");
	insere(l, 45, "A50");
	insere(l, 36, "A20");
	insere(l, 42, "A40");

	printf("Exibindo lista completa: \n\n");
	exibe(l);
	printf("\n\n===== \n\n");

	printf("Exibindo parte 1 da lista: \n\n");
	Lista* l2 = quebraAoMeio(l);
	exibe(l);
	printf("\n\n===== \n\n");

	printf("Exibindo parte 2 da lista: \n\n");
	exibe(l2);
	


	return 0;
}


Lista* cria()//Função que aloca espaço na memória e bota o primeiro valord a lista como NULL;
{
	Lista *l = (Lista*)malloc(sizeof(Lista));

	if (l == NULL)
	{
		printf("Erro ao alocar memória para l");
		exit(1);
	}
	l->prim = NULL;
	return l;
}

void insere(Lista* l, int cod, char* nome)
{
	No* n = (No*)malloc(sizeof(No));
	n->info = (Info*)malloc(sizeof(Info));

	n->info->codigo = cod;
	strcpy(n->info->nome, nome);

	/*n->prox = l->prim;
	l->prim = n; Obs: Isso é para adicionar na frente, do primeiro, ou seja, fora de ordem. */

	No* p;
	n->prox = NULL;
	if (l->prim == NULL)
	{
		l->prim = n;
	}
	else
	{

		No* p;

		p = l->prim;//Guardo o primeiro elemento na variável p
		while (p->prox != NULL)//Enquanto o ponteiro para proximo do elemento que está sendo conferido agora não for NULL
		{
			p = p->prox;//p é igual ao elemento seguninte (isso faz com oque o ponteiro para proximo chegue no ultimo)
		}

		p->prox = n;//Quando sair do while o p atual é p ultimo elemento, então o proximo dele é NULL, ou seja, você quer trocar o p->prox dele para o elemento que você criou

	}

}

void exibe(Lista* l)
{	
	No* p = l->prim;
	int cont = 1;
	while (p != NULL)
	{
		printf("Elemento %d ", cont);
		printf("Cod: %d ", p->info->codigo);
		printf("Nome: %s", p->info->nome);
		cont++;
		p = p->prox;
		printf("\n\n");
	}
}

Lista* quebraAoMeio(Lista* l)
{
	No* p = l->prim;

	int qtdEle = 0;
	while (p != NULL)
	{
		qtdEle++;
		p = p->prox;
	}//Conta quantos elementos

	Lista* l2 = cria();
	
	p = l->prim;
	int tamAteMetade;
	int indexMetade;
	if (qtdEle % 2 == 0)//Se for par;
	{
		tamAteMetade = qtdEle / 2;
		indexMetade = tamAteMetade - 1;//Determino qual o index da metade
	}
	else if(qtdEle % 2 != 0 )
	{
		tamAteMetade = qtdEle / 2;
		indexMetade = tamAteMetade;//Determino qual o index da metade
	}

	int index = 0;
	while (p != NULL)
	{
		p = p->prox;
		index++;
		if (index == indexMetade)
			break;
	}

	l2->prim = p->prox;
	p->prox = NULL;
	return l2;
}

