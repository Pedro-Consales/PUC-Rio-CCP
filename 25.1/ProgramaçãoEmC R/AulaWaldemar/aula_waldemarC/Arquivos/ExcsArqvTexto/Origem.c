#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{


	//1)

	//FILE* arqEntrada = fopen("contarLinhasArq.txt", "r");
	//if (arqEntrada == NULL) 
	//{
	//	printf("Erro ao abrir arquvio");
	//	exit(1);
	//}

	//char linha[1000];
	////maneira 1)

	//int contador = 0;
	//while (fscanf(arqEntrada, " %[^\n]\n", linha) == 1)
	//{
	//	contador++;

	//}

	//printf("%d", contador);
	//
	//fclose(arqEntrada);

	//maneira2
	//FILE* arqEntrada = fopen("contarLinhasArq.txt", "r");
	//if (arqEntrada == NULL)
	//{
	//	printf("Erro ao abrir arquvio");
	//	exit(1);
	//}

	//char linha[1000];

	//int contador = 0;
	//while (!feof(arqEntrada)) //"feof não prevê o fim do arquivo. Ele detecta depois que você tentou ler a mais." Porque feof(arq) só fica verdadeiro depois que você já tentou ler além do fim do arquivo. Ou seja: Então ele pode contar um elemento a mais como lixo
	//{	
	//	// como feof não prevê o fim do arquivo, caso utilize desse jeito, é preferivel que se faça uma outra verificação para evitar erros
	//	if (fscanf(arqEntrada, " %[^\n]\n", linha) == 1)
	//		contador++;
	//	//Que a pesar de diferente, repete o passo da maneira 1


	//}

	//printf("%d", contador);

	//fclose(arqEntrada);

	//return 0;


	//=================================================



	//2)

	/*Faça um programa que receba do usuário um arquivo texto e um caracter.Mostre na
	tela quantas vezes aquele caractere ocorre dentro do arquivo.*/


	//FILE* arqEntrada = fopen("contaLetras.txt", "r");
	//if (arqEntrada == NULL)
	//{
	//	printf("Erro ao abrir arquvio para leitura");
	//	exit(1);
	//}

	//char c;
	//printf("Informe um caracter que voce deseja contar dentro do aqruivo: ");
	//scanf(" %c", &c);//Espaço antes do c para o scanf desconsiderar qualuqer caracter a mais: Ex o "enter" na hora em que eu retorno o valor do usuário.

	//printf("\n");

	//char linha[10000];

	//int contadorC = 0;
	//while(fscanf(arqEntrada, " %[^\n]\n", linha) == 1)
	//{
	//	int tamStr = strlen(linha);
	//	for (int i = 0; i < tamStr; i++)
	//		if (linha[i] == c)
	//			contadorC++;
	//}
	//
	//printf("O caractere '%c' eh econtrado %dx no arquivo\n\n", c, contadorC);

	//return 0;

	//================================================
	// 
	//3)
	// Faca um programa para ler um arquivo linha a linha e escreve‐la na tela. Dica: use o 
	// fscanf da mesma forma que usaria o scanf para ler uma string ate encontrar o \n. 

	/*FILE* arqEntrada = fopen("linhaAlinha.txt", "r");
	if(arqEntrada == NULL)
	{
		printf("Erro ao abrir o arqv);
		exit(1);
	}

	char linha[1000];
	int qtdLinhas = 3;
	for (int i = 0; i < qtdLinhas; i++)
	{
		fscanf(arqEntrada, "%[^\n]\n", linha);
		printf("%s\n", linha);
	}

	return 0;*/

	//===============================================

	//4)
	//Faça um programa que receba dois arquivos do usuário, e crie um terceiro arquivo
	//com o conteúdo dos dois primeiros juntos(o conteúdo do primeiro seguido do
	//	conteúdo do segundo).

	//FILE* arqEntrada1 = fopen("arqv1.txt", "r");
	//if(arqEntrada1 == NULL)
	/*{
		printf("Erro ao abrir arquvio");
		exit(1);
	}*/

	//FILE* arqEntrada2 = fopen("arqv2.txt", "r");
	//if(arqEntrada2 == NULL)
	/*{
		printf("Erro ao abrir arquvio");
		exit(1);
	}*/

	//FILE* arqSaida = fopen("arqvSaida.txt", "w");
	//if(arqSaida == NULL)
	/*{
		printf("Erro ao abrir arquvio");
		exit(1);
	}*/

	//char linha[1000];
	//int qtdLinhasArq1 = 3;
	//int qtdLinhasArq2 = 3;

	//for (int i = 0; i < qtdLinhasArq1; i++)
	//{
	//	fscanf(arqEntrada1, "%[^\n]\n", linha);
	//	printf("%s\n", linha);
	//	fprintf(arqSaida, "%s\n", linha);
	//}
	//fclose(arqEntrada1);
	//
	//fprintf(arqSaida, "\n");//Teste para ver se era assim que eu pulava mais uma linha. Funciona que nem o printf() normal

	//for (int i = 0; i < qtdLinhasArq2; i++)
	//{
	//	fscanf(arqEntrada2, "%[^\n]\n", linha);
	//	printf("%s\n", linha);
	//	fprintf(arqSaida, "%s\n", linha);
	//}
	//fclose(arqEntrada2);

	//fclose(arqSaida);

	//return 0;

	//===================================
	
	//5)
	//Faça um programa de criptografia de dados, ou seja, um programa capaz de ler um
	//arquivo texto, codificar este arquivo através de alguma técnica de alteração do código
	//ASCII(exemplo: somar 1 ao valor ASCII de cada caracter), e escrever em disco o
	//arquivo codificado. Crie um outro programa que descriptografe um arquivo criado pelo
	//programa de criptografia, realizando a operação inversa : ler o arquivo do disco,
	//descodificar e escrever o novo arquivo em disco descriptografado. Lembre‐se que para
	//que seja possível criptografar / descriptografar um arquivo a função de codificação deve
	//possuir uma função inversa.Exemplo de código de criptografia :
	//tamanho = strlen(linha);
	//for (i = 0; i < tamanho; i++)
	//	linha_cripto[i] = linha[i] + 1; /* Soma 1 ao código de cada caracter da string */
	//linha_cripto[tamanho] = ’\0’; /* Adiciona a marca de fim de string */
	//Desafio: Você consegue desenvolver uma função de criptografia / descriptografia que
	//seja mais sofisticada e menos óbvia do que esta ?


	//FILE* arqEntrada = fopen("arqv2.txt", "rt");
	//if (arqEntrada == NULL) {
	//	printf("Erro ao abrir o arquivo.\n");
	//	exit(1);
	//}
	//FILE* arqSaidaEncripted = fopen("arqCriptografado.txt", "wt");
	//if (arqSaidaEncripted == NULL) {
	//	printf("Erro ao abrir o arquivo.\n");
	//	exit(1);
	//}
	//FILE* arqSaidaDecripted = fopen("arqDescriptografado.txt", "wt");
	//if (arqSaidaDecripted == NULL) {
	//	printf("Erro ao abrir o arquivo.\n");
	//	exit(1);
	//}


	//char linha[1000];
	//char linha_encripted[1000];
	//char linha_decripted[1000];
	//int qtdLinhas = 3;


	//for (int i = 0; i < qtdLinhas; i++)
	//{

	//	fscanf(arqEntrada, " %[^\n]\n", linha);

	//	int tamStr = strlen(linha);
	//	int j = 0;
	//	for (j; j < tamStr; j++)
	//	{
	//		linha_encripted[j] = linha[j] + 1;
	//		linha_decripted[j] = linha_encripted[j] - 1;
	//	}
	//	
	//	linha_encripted[j] = '\0';
	//	linha_decripted[j] = '\0';
	//	printf("%s\n\n", linha_encripted);
	//	printf("%s\n\n", linha_decripted);
	//	fprintf(arqSaidaEncripted, "%s\n", linha_encripted);
	//	fprintf(arqSaidaDecripted, "%s\n", linha_decripted);
	//	

	//}
	//fclose(arqEntrada);
	//fclose(arqSaidaEncripted);
	//fclose(arqSaidaDecripted);



	//return 0;


	//=================================

	FILE* arqEntrada = fopen("html.txt", "rt");
	if (arqEntrada == NULL)
	{
		printf("Erro ao abrir o arquivo de entrada");
		exit(1);
	}

	FILE* arqSaida = fopen("htmlSemTag.txt", "wt");
	if (arqSaida == NULL)
	{
		printf("Erro ao abrir o arquivo de Saida");
		exit(1);
	}
	char c;
	while (fscanf(arqEntrada, "%c", &c) == 1)
	{
		if (c == '<')
		{
			fscanf(arqEntrada, " %*[^>]>");
			printf("%c\n", c);
		}
		else
		{
			fprintf(arqSaida, "%c", c);
			printf("%c", c);
		}

	}
	fclose(arqEntrada);
	fclose(arqSaida);

	return 0;
}