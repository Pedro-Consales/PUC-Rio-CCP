#include<stdio.h>





void guardaArquvios(char* arqEntrada, char* arq_saidaTitulos, char* arq_saidaNum);
void OnR(char* arq_entradaTitulos, char* arq_entradaNum);


int main(void)
{


	guardaArquvios("distribuidora.txt", "saidaTitulos.txt", "saidaNum.dat");
	OnR("saidaTitulos.txt", "saidaNum.dat");

}

void guardaArquvios(char* arqEntrada, char* arq_saidaTitulos, char* arq_saidaNum)
{
	FILE* arqMain = fopen(arqEntrada, "rt");
	if (arqMain == NULL)
	{
		printf("Erro ao abrir o arquivo de entrada main");
		exit(1);
	}
	FILE* arqSaidaTitulos = fopen(arq_saidaTitulos, "wt");
	if (arqSaidaTitulos == NULL)
	{
		printf("Erro ao abrir o arquivo de saida Titulos");
		exit(1);
	}
	FILE* arqSaidaNum = fopen(arq_saidaNum, "wb");
	if (arqSaidaNum == NULL)
	{
		printf("Erro ao abrir o arquivo de saida Titulos");
		exit(1);
	}


	
	char bufferTitulo[128];
	int q[5];
	while (fscanf(arqMain, " %[^/]/ %d %d %d %d %d", bufferTitulo, &q[0], &q[1], &q[2], &q[3], &q[4]) == 6)
	{

		fprintf(arqSaidaTitulos, "%s\n", bufferTitulo);
		fwrite(q, sizeof(int),5, arqSaidaNum);


	}

	fclose(arqMain);
	fclose(arqSaidaTitulos);
	fclose(arqSaidaNum);

}



void OnR(char* arq_entradaTitulos, char* arq_entradaNum)
{

	FILE* arqMainTitle = fopen(arq_entradaTitulos, "rt");
	if (arqMainTitle == NULL)
	{
		printf("Erro ao abrir o arquivo de entrada main title");
		exit(1);
	}
	FILE* arqMainNum = fopen(arq_entradaNum, "rb");
	if (arqMainNum == NULL)
	{
		printf("Erro ao abrir o arquivo de entrada main num");
		exit(1);
	}

	char bufferTitulo[128];
	int q[5];
	while (fscanf(arqMainTitle, " %[^\n]\n", bufferTitulo) == 1)
	{

		printf("%s\n", bufferTitulo);
		fread(q, sizeof(int), 5, arqMainNum);

		printf("%d %d %d %d %d\n\n", q[0], q[1], q[2], q[3], q[4]);

	}

}