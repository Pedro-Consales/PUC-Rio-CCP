#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int retornaIncdicieMaior(char** vetorDeStrings, int n);

int main(void)
{

	FILE* arqEntrada = fopen("arq.txt", "rt");
	if (arqEntrada == NULL)
	{
		printf("Erro ao abrir o arquivo de entrada");
		exit(1);
	}
	FILE* arqSaidaBin = fopen("arqSaida.dat", "wb");
	if (arqSaidaBin == NULL)
	{
		printf("Erro ao abrir o arquivo de saida bin");
		exit(1);
	}
	

	int qtdLinhas;
	fscanf(arqEntrada, " %d", &qtdLinhas);

	char** vetorStr = (char**)malloc(qtdLinhas * sizeof(char*));
	if (vetorStr == NULL)
	{
		printf("Erro ao alocar memoria para o novo vetor");
		exit(1);
	}

	char bufferNome[128];
	char bufferProfissao[128];
	int bufferTamStr;
	for (int i = 0; i < qtdLinhas; i++)
	{
		fscanf(arqEntrada, " %[^:]: %[^\n]\n", bufferNome, bufferProfissao); //Dúvida -> o strlen() está contando mais uma unidade que não deveria, pq?

		bufferTamStr = strlen(bufferNome) + strlen(bufferProfissao);

		//printf("%s %s -> %d + %d = %d\n\n", bufferNome, bufferProfissao, strlen(bufferNome), strlen(bufferProfissao), bufferTamStr);

		vetorStr[i] = (char*)malloc((bufferTamStr + 2) * sizeof(char));
		if (vetorStr[i] == NULL)
		{
			printf("Erro ao alocar memoria para o novo vetor");
			exit(1);
		}
		char* bufferStrNova = (char*)malloc((bufferTamStr + 2) * sizeof(char));
		if (bufferStrNova == NULL)
		{
			printf("Erro ao alocar memoria para o novo vetor");
			exit(1);
		}

		strcpy(bufferStrNova, bufferProfissao);
		strcat(bufferStrNova," ");
		strcat(bufferStrNova, bufferNome);
		strcpy(vetorStr[i], bufferStrNova);

		printf("%s\n", vetorStr[i]);

		free(bufferStrNova);
	}

	printf("%d\n\n", qtdLinhas);

	int indicie = retornaIncdicieMaior(vetorStr, qtdLinhas); 
	printf("O indicie do maior elemento eh %d\n", indicie);
	printf("%s\n",vetorStr[indicie]);
	fclose(arqEntrada);

	int tamMaior = strlen(vetorStr[indicie]);
	fwrite(&tamMaior, sizeof(int), 1, arqSaidaBin);
	for (int i = 0; i < tamMaior; i++)
	{
		fwrite(&vetorStr[indicie][i], sizeof(char), 1, arqSaidaBin);
	}
	fclose(arqSaidaBin);

	FILE* arqLeituraBin = fopen("arqSaida.dat", "rb");
	if (arqLeituraBin == NULL)
	{
		printf("Erro ao abrir o arquivo de leitura bin");
		exit(1);
	}
	int tamMaiorArqv;
	fread(&tamMaiorArqv, sizeof(int), 1, arqLeituraBin);
	printf("%d\n",tamMaiorArqv);
	char* strReMontada = (char*)malloc((tamMaiorArqv + 1) * sizeof(char));
	char c;
	int j = 0;
	for (j; j < tamMaiorArqv; j++)
	{
		fread(&c, sizeof(char), 1, arqLeituraBin);
		strReMontada[j] = c;
	}
	strReMontada[j] = '\0';
	printf("%s", strReMontada);
	fclose(arqLeituraBin);

	return 0;
}

int retornaIncdicieMaior(char** vetorDeStrings, int n)
{

	int maiorStrInicial = strlen(vetorDeStrings[0]);
	int index;
	char* maiorStr;
	for(int i = 0; i < n; i++)
	{
		int tamEleAtual = strlen(vetorDeStrings[i]);
		if (tamEleAtual > maiorStrInicial)
		{
			maiorStrInicial = tamEleAtual;
			maiorStr = vetorDeStrings[i];
			index = i;
		}
	}

	return index;
}