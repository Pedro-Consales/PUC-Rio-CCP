#include<stdio.h>
#include<stdlib.h>


struct aluno
{
	char nome[81];
	float vetorNotas[3];
};
typedef struct aluno Aluno;


void salva_cadastro(int n, Aluno* v);
Aluno* leia_arquivo(char* nome_arquivo);
void exibe_aluno(int n);


int main(void)
{
	Aluno* vetAlunos;

	vetAlunos = leia_arquivo("notas.txt");
	salva_cadastro(5, vetAlunos);



	int i = 0;
	for (i; i < 5; i++)
	{
		printf("Aluno %d\n\n", i + 1);
		printf("Nome: %s\n", vetAlunos[i].nome);
		printf("Nota 1: %.2f\n", vetAlunos[i].vetorNotas[0]);
		printf("Nota 2: %.2f\n", vetAlunos[i].vetorNotas[1]);
		printf("Nota 3: %.2f\n", vetAlunos[i].vetorNotas[2]);

		printf("\n\n=================\n\n");

	}

	exibe_aluno(2);

	return 0;
}



Aluno* leia_arquivo(char* nome_arquivo)
{

	FILE* arqEntrada = fopen(nome_arquivo, "rt");
	if (arqEntrada == NULL)
	{
		printf("Erro ao abrir arquivo de entrada");
		exit(1);
	}

	Aluno* vetAlunos = (Aluno*)malloc(5 * sizeof(Aluno));

	int i = 0;

	while (fscanf(arqEntrada, " %[^:]: %f %f %f", vetAlunos[i].nome, &vetAlunos[i].vetorNotas[0], &vetAlunos[i].vetorNotas[1], &vetAlunos[i].vetorNotas[2]) == 4)
	{
		i++;
	}
	fclose(arqEntrada);

	return vetAlunos;
}

void salva_cadastro(int n, Aluno* v)
{

	FILE* SavedFile = fopen("cadastros_salvos.dat", "wb");
	if (SavedFile == NULL)
	{
		printf("Erro ao abrir o arquivo de saida .dat");
		exit(1);
	}

	fwrite(v, sizeof(Aluno), n, SavedFile);
	fclose(SavedFile);
}

void exibe_aluno(int n)
{
	FILE* SavedFile = fopen("cadastros_salvos.dat", "rb");
	if (SavedFile == NULL)
	{
		printf("Erro ao abrir o arquivo de entrada .dat");
		exit(1);
	}

	Aluno alunoDaPos;

	fseek(SavedFile, (n-1) * sizeof(Aluno), SEEK_SET); //Movimenta o cursos do arquivo do início até o elemento desejado
	fread(&alunoDaPos, sizeof(Aluno), 1, SavedFile);

	printf("O aluno que voce busca eh o:\n");
	printf("Aluno %d\n\n", n);
	printf("Nome: %s\n", alunoDaPos.nome);
	printf("Nota 1: %.2f\n", alunoDaPos.vetorNotas[0]);
	printf("Nota 2: %.2f\n", alunoDaPos.vetorNotas[1]);
	printf("Nota 3: %.2f\n", alunoDaPos.vetorNotas[2]);

	fclose(SavedFile);
}