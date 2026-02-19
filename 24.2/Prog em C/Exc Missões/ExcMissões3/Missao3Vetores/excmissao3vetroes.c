//1.
//a) Escreva um programa para ler 10 valores inteiros e mostrar todos os menores que o último
//valor lido(o décimo).
//b) Inclua agora no programa as seguintes funções :
//calculaMedia() que : -recebe um vetor de inteiros, o número de elementos do vetor e - retorna a média dos valores armazenados.
//busca1() que : -recebe um vetor de inteiros, o número de elementos do vetor e um valor inteiro X - retorna 1, se X for encontrado no vetor, ou 0, caso contrário
//busca2() que : -recebe um vetor de inteiros, o número de elementos do vetor e um valor inteiro X, -retorna a posição de X no vetor, se X for encontrado no vetor, ou - 1, caso contrário.
//verificaOrd() que : -recebe um vetor de inteiros e o número de elementos do vetor - retorna 1, se o vetor encontra - se ordenado crescentemente, ou 0, caso contrário.
//Inverte() que : -recebe um vetor de inteiros já preenchido, o número n de elementos desse vetor, e um
//segundo vetor de inteiros - devolve no segundo vetor os n elementos do primeiro vetor, na ordem inversa à que se
//encontram originalmente.
//c) Inclua na função main um teste para cada uma das funções acima.

//#include <stdio.h>
//#include <stdlib.h>
//#define TOT 10
//
//float calculaMedia(int* vetor, int n) {
//
//	int soma;
//	int i;
//
//	soma = 0;
//	for (i = 0; i < n; i++) {
//
//		soma = soma + vetor[i];
//
//
//	}
//
//	return soma / n;
//
//}
//
//
//int busca1(int* vetor, int n, int valorX) {
//
//
//	int i;
//
//	for (i = 0; i < n; i++) {
//
//		if (vetor[i] == valorX) {
//
//			return 1;
//		}
//	}
//
//	return 0;
//
//}
//
//
//int busca2(int* vetor, int n, int valorX) {
//
//	int i;
//
//	for (i = 0; i < n; i++) {
//
//		if (vetor[i] == valorX) {
//
//			return i + 1;
//
//		}
//	}
//	return -1;
//}
//
//
//int verificaOrd(int* vetor, int n) {
//
//	int i;
//
//	for (i = 0;i < n - 1;i++) {
//
//		if (vetor[i] > vetor[i + 1]) {
//
//			return 0;
//
//		}
//	}
//	return 1;
//}
//
//void inverte(int* vetorPreenchido, int qtdEleVetorPreenchido, int* vetor2Preenchido) {
//
//	int i;
//
//	for (i = 0;i < qtdEleVetorPreenchido;i++) {
//
//		vetor2Preenchido[i] = vetorPreenchido[qtdEleVetorPreenchido - 1 - i];
//
//	}
//}
//
//
//
//
//int main(void) {
//	int i, numeros[TOT];
//	float media;
//	int valorX = 2, vrfValorX;
//	int posValorX;
//	int ordemVetor;
//	int Lista1[5] = { 2,4,6,8,10 };
//	int Lista2[5];
//
//
//	for (i = 0; i < TOT; i++) {
//
//		printf("Digite um numero inteiro: ");
//		scanf("%d", &numeros[i]);
//
//	}
//
//	printf("Os numeros menores que %d sao : ", numeros[9]);
//
//
//
//	for (i = 0;i < 9;i++) {
//
//		if (numeros[i] < numeros[9]) {
//
//			printf("%d ", numeros[i]);
//
//		}
//
//	}
//
//
//
//
//	printf("\n");
//	media = calculaMedia(numeros, TOT);
//	printf("A media dos valores eh: %.1f\n", media);
//
//
//	if (busca1(numeros, TOT, valorX) == 1) {
//		printf("O valor %d esta no vetor\n", valorX);
//	}
//	else
//	{
//		printf("O valor %d nao esta no vetor\n", valorX);
//	}
//
//	posValorX = busca2(numeros, TOT, valorX);
//	if (posValorX != -1) {
//
//		printf("A posicao do valor X eh: %d\n", posValorX);
//
//	}
//	ordemVetor = verificaOrd(numeros, TOT);
//	if (ordemVetor == 1) {
//
//		printf("O vetor esta em ordem CRESCENTE\n");
//
//	}
//	else if (ordemVetor == 0) {
//
//		printf("O vetor NAO esta em ordem CRESCENTE\n");
//
//	}
//	inverte(Lista1, 5, Lista2);
//	printf("O valor invertido do vetor preenchdio: ");
//	for (i = 0;i < 5;i++) {
//
//		printf("%d ", Lista2[i]);
//
//	}
//
//
//	return 0;
//
//}
//==========================================================================================================================
// 2. Uma escola deseja escolher o rei e a rainha da escola através de uma eleição onde participarão 
// todos os alunos. Cada aluno escolherá um rei e uma rainha. Existem 10 candidatos a rei e 10 
// candidatas a rainha. Os candidatos a rei escolheram números quaisquer para representá-los e as 
// candidatas a rainha possuem número de 1 a 10. 

//Faça um programa que inicialmente obtenha a 
// quantidade de alunos da escola e os códigos escolhidos pelos candidatos a rei. A seguir, para 
// cada aluno deverão ser lidos os votos para rei e para rainha. Este programa deverá exibir o rei e 
// a rainha da escola e o lanterninha e a lanterninha da escola, ou seja, aqueles que tiveram mais 
// votos e menos votos. 

//Faça pelo menos 2 funções além da main ( ) e da função abaixo:  
// Crie a função min_max: que recebe a quantidade de elementos de um vetor e o próprio vetor 
// retornando as posições onde estão o menor valor e o maior valor do vetor. 

#include <stdio.h>
#define TOT 10

void exibe_resultados(int* vetorRei, int* vetorRainha, int qtdEleVet) {

	int i;

	printf("\nOs resultados para REI sao:\n");
	for (i = 0;i < qtdEleVet;i++) {

		printf("%d,	", vetorRei[i]);

	}
	printf("\nOs resultados para RAINHA sao:\n");
	for (i = 0;i < qtdEleVet;i++) {

		printf("%d,	", vetorRainha[i]);

	}
}

void conta_votos(int* vetorCadidadosRei, int numVotadoREI, int* resultVotadosREI, int* vetorCadidadosRainha, int numVotadoRainha, int* resultVotadosRainha) {

	int cont;

	cont = 0;
	while (cont < TOT) {

		if (vetorCadidadosRei[cont] == numVotadoREI) {

			resultVotadosREI[cont]++;

		}
		if (vetorCadidadosRainha[cont] == numVotadoRainha) {

			resultVotadosRainha[cont]++;

		}
		cont += 1;
	}

}

void printVetor(int* vetor, int qtdEleVetor) {

	int i;

	for (i = 0;i < qtdEleVetor;i++) {

		printf("%d	", vetor[i]);
	}
}

void min_max(int qtdEleVetor, int* vetor, int qtdALunos, int* posMenor, int* posMaior) {

	int i;
	int menorValor = qtdALunos;
	int maiorValor = 0;

	*posMaior = 0;
	*posMenor = 0;

	for (i = 0;i < qtdEleVetor;i++) {

		if (vetor[i] > maiorValor) {

			maiorValor = vetor[i];
			*posMaior = i + 1;

		}
		if (vetor[i] < menorValor) {

			menorValor = vetor[i];
			*posMenor = i + 1;

		}
	}
}

int main(void) {

	int i;
	int qtdALunos;
	int numVotadoRei, numVotadoRainha;
	int CandidatosRei[TOT];
	int CandidatosRainha[TOT];
	int ResultVotadosREI[TOT] = { 0,0,0,0,0,0,0,0,0,0 };
	int ResultVotadosRainha[TOT] = { 0,0,0,0,0,0,0,0,0,0 };
	int posMenorRei, posMaiorRei, posMenorRainha, posMaiorRainha;

	printf("Digite a quantidade de alunos na escola:");
	scanf("%d", &qtdALunos);


	for (i = 0;i < TOT;i++) {

		printf("\nDigite o numero de 11 ao infinito para o candidato a rei %d:", i + 1);
		scanf("%d", &CandidatosRei[i]);

		printf("Digite o numero de 1 a 10 do candidato a rainha %d:", i + 1);
		scanf("%d", &CandidatosRainha[i]);
	}

	printf("\nOs numeros dos candidatos a REI sao: \n");
	printVetor(CandidatosRei, TOT);

	printf("\nOs numeros dos candidatos a RAINHA sao:\n");
	printVetor(CandidatosRainha, TOT);

	for (i = 0;i < qtdALunos;i++) {

		printf("\n");
		printf("\nAluno %d, o seu voto para o REI: ", i + 1);
		scanf("%d", &numVotadoRei);

		printf("Aluno %d, o seu voto para a RAINHA: ", i + 1);
		scanf("%d", &numVotadoRainha);

		conta_votos(CandidatosRei, numVotadoRei, ResultVotadosREI, CandidatosRainha, numVotadoRainha, ResultVotadosRainha);
	}

	exibe_resultados(ResultVotadosREI, ResultVotadosRainha, TOT);

	min_max(TOT, ResultVotadosREI, qtdALunos, &posMenorRei, &posMaiorRei);

	printf("\n")

		printf("\nLogo o REI %d foi eleito, com a maior quantidade de votos\n", posMaiorRei);

	printf("O REI %d teve menos votos\n", posMenorRei);

	min_max(TOT, ResultVotadosRainha, qtdALunos, &posMenorRainha, &posMaiorRainha);

	printf("\nLogo a RAINHA %d foi eleito, com a maior quantidade de votos\n", posMaiorRainha);

	printf("A RAINHA %d teve menos votos", posMenorRainha);
}