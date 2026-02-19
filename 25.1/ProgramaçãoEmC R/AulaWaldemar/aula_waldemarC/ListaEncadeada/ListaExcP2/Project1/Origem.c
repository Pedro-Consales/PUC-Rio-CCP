#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct aluno
{
	char nomeCompleto[81];
	int numMat;
	float p1, p2, p3;
};
typedef struct aluno Aluno;

typedef struct elemento Elemento;
struct elemento
{
	Aluno* infoAluno;
	Elemento* prox;
};

typedef struct lista Lista;
struct lista
{
	Elemento* prim;
};




Aluno* leia_arquivo(char* nome_arquivo, int* pn);
void salva_binario(int n, Aluno* vet, char* nome_arquivo);
Aluno* leia_aluno(char* nome_arquivo, int n);
Lista* crialista(int n, Aluno* vet);
void exibe_lista(Lista* l);
void exibe_rev(Lista* l);

int main(void)
{

	int qtdAlunos;

	Aluno* listaAlunos = leia_arquivo("alunos.txt", &qtdAlunos);

	printf("Qtd de alunos = %d\n\n", qtdAlunos);

	for (int i = 0; i < qtdAlunos; i++)
	{
		printf("%d\n", listaAlunos[i].numMat);
	}

	salva_binario(qtdAlunos, listaAlunos, "alunos.dat");

	int n = 0;
	Aluno* alunoAtual = leia_aluno("alunos.dat", n);

	printf("O elemento da posicao %d tem a matricula %d\n\n\n", n, alunoAtual->numMat);


	Lista* listaEncadeda = crialista(qtdAlunos, listaAlunos);

	exibe_lista(listaEncadeda);

	printf("\n\n===================================\n\n");

	exibe_rev(listaEncadeda);



	return 0;
}

Aluno* leia_arquivo(char* nome_arquivo, int* pn)
{
	FILE* arqEntrada = fopen(nome_arquivo, "rt");
	if (arqEntrada == NULL)
	{
		printf("Erro ao abrir arquivo de entrada");
		exit(1);
	}

	int qtdAlunos;
	fscanf(arqEntrada, " %d", &qtdAlunos);
	*pn = qtdAlunos;

	Aluno* listaAlunos = (Aluno*)malloc(qtdAlunos * sizeof(Aluno));

	for (int i = 0; i < qtdAlunos; i++)
	{
		fscanf(arqEntrada, " %[^:]: %d %f %f %f", listaAlunos[i].nomeCompleto, &listaAlunos[i].numMat, &listaAlunos[i].p1, &listaAlunos[i].p2, &listaAlunos[i].p3);
	}


	fclose(arqEntrada);
	return listaAlunos;
}

void salva_binario(int n, Aluno* vet, char* nome_arquivo)
{
	FILE* arqEntradaBin = fopen(nome_arquivo, "wb");
	if (arqEntradaBin == NULL)
	{
		printf("Erro ao abrir arquivo bin");
		exit(1);
	}

	fwrite(&n, sizeof(int), 1, arqEntradaBin);
	fwrite(vet, sizeof(Aluno), n, arqEntradaBin);
	fclose(arqEntradaBin);
}


Aluno* leia_aluno(char* nome_arquivo, int n)
{
	Aluno* alunoN = (Aluno*)malloc(sizeof(Aluno));

	FILE* arqEntradaBin = fopen(nome_arquivo, "rb");
	if (arqEntradaBin == NULL)
	{
		printf("Erro ao alocar memoria para o arquvido bin para leitura");
		exit(1);
	}

	int qtdAluno;

	fread(&qtdAluno, sizeof(int), 1, arqEntradaBin);
	fseek(arqEntradaBin, sizeof(Aluno) * (n), SEEK_CUR); //Poderia ler a lista toda, porém, assim gasta menos memória
	fread(alunoN, sizeof(Aluno), 1, arqEntradaBin);
	
	return alunoN;
}

Lista* crialista(int n, Aluno* vet)
{

	Lista* l = (Lista*)malloc(sizeof(Lista));
	if (l == NULL)
	{
		printf("Erro ao alocar memoria para lista");
		exit(1);
	}

	l->prim = NULL;
	//Essa aqui seria a função cria, sem fazer a função


	Aluno alunoAtual; 
	for (int i = 0; i < n; i++)
	{
		
		Elemento* p = (Elemento*)malloc(sizeof(Elemento));
		if (p == NULL)
		{
			printf("Erro ao alocar memoria para elemento p");
			exit(1);
		}
		p->infoAluno = (Aluno*)malloc(sizeof(Aluno));
		if (p->infoAluno == NULL)
		{
			printf("Erro ao alocar memoria par aluno");
			exit(1);
		}

		alunoAtual = vet[i];
		
		strcpy(p->infoAluno->nomeCompleto, alunoAtual.nomeCompleto);
		p->infoAluno->numMat = alunoAtual.numMat;
		p->infoAluno->p1 = alunoAtual.p1;
		p->infoAluno->p2 = alunoAtual.p2;
		p->infoAluno->p3 = alunoAtual.p3;

		p->prox = NULL;


		
		if (l->prim == NULL)
		{
			l->prim = p;
		}
		else
		{
			Elemento* e = l->prim;
			while (e->prox != NULL)
			{
				e = e->prox;
			}
			e->prox = p;
		}
	}
	return l;
}

void exibe_lista(Lista* l)
{
	Elemento* p = l->prim;
	while (p != NULL)
	{
		printf("Nome: %s\n Matricula: %d\n Nota P1: %.2f\n Nota P2: %.2f\n Nota P3: %.2f\n\n", p->infoAluno->nomeCompleto, p->infoAluno->numMat, p->infoAluno->p1, p->infoAluno->p2, p->infoAluno->p3);
		p = p->prox;
	}
}

void exibe_rev(Lista* l)
{
	if (l == NULL || l->prim == NULL)
	{
		return;
	}
	Lista sublista;
	sublista.prim = l->prim->prox;

	exibe_rev(&sublista); 

	printf("Nome: %s\n"
		"Matricula: %d\n"
		"Nota P1: %.2f\n"
		"Nota P2: %.2f\n"
		"Nota P3: %.2f\n\n",
		l->prim->infoAluno->nomeCompleto,
		l->prim->infoAluno->numMat,
		l->prim->infoAluno->p1,
		l->prim->infoAluno->p2,
		l->prim->infoAluno->p3);
}

void retira_aluno(Lista* lst, char* nome)
{
	Elemento* p = lst->prim;
	Elemento* ant = NULL;
	Elemento* temp;
	while (p != NULL)
	{
		
		if (strcmp(p->infoAluno->nomeCompleto, nome) == 0)//Verifico se o atual tem nome igual
		{
			temp = p;
			if (ant == NULL)//Verifico se o anterior é NULL
			{//No primeiro caso, ele vai ser igual a NULL pois antes do primeiro elemento não existe ninguém
				lst->prim = p->prox;
			}
			else//Caso geral, vai entrar em todos os outros casos
			{
				ant->prox = p->prox;
			}

			p = p->prox; //Avança p para o elemnto seguinte

			// libera memória alocada para o aluno e para o nó
			free(temp->infoAluno);
			free(temp);

			return;
		}

		ant = p;
		p = p->prox;

	}


}
