#include <stdio.h>
#include <stdlib.h>

//1. Faça uma função que retorna a soma, a diferença e o produto entre dois números. Os resultados devem retornar por 
//parâmetros passados por referência.

//preciso entender melhor o que é passar por referência e oq está acontecendo aqui

void returnOperacoes(int num1, int num2, int* soma, int* dif, int* produto) { //declado soma como o conteudo do endereço que foi passado

	*soma = num1 + num2;//altero o conteudo do endereço que foi passado

	*dif = num1 - num2;

	*produto = num1 * num2;

	return;

}

//2. Faça uma função que retorna a razão entre dois números.A função deve retornar pelo comando return o valor 1 se a
//operação foi possível e o valor 0 se a operação não foi possível(divisão por zero, por exemplo).O resultado da divisão
//deve retornar por um parâmetro por referência.

int retornaRazao(float numerador, float denominador, float* result) {

	*result = numerador / denominador;

	if(denominador == 0){
		return 0;
	}
	else {
		return 1;
	}

}
/*3) Desenvolva um programa que leia a quantidade total de segundos e converta para Horas, Minutos e Segundos.
Imprima o resultado da conversão no formato HH : MM:SS.Para isso, utilize a função com protótipo
void converteHora(int total segundos, int* hora, int* min, int* seg).*/

void converteHora(int total_segundos, int* hora, int* min, int* seg) //Entender o cálculo de horas minutos e segundos;
{

	*hora = total_segundos / 3600; 
	*min = (total_segundos % 3600) / 60;
	*seg = total_segundos % 60;

}

//4). Faça um programa que lê um conjunto de 10 valores inteiros e verifica se algum dos valores é igual a média dos 
//mesmos. Feito na Main

//5) Faça um programa para calcular o produto escalar de dois vetores de tamanho n. Por exemplo: Feito na Main

//6) Faça um programa para calcular o produto vetorial de dois vetores de tamanho 3. Por exemplo: Feito na Main

//7) NÂO ENTENDI  Calcule o valor de um polinômio   
//para k valores de x diferentes.São dados n(grau do polinômio), um vetor a = { a0, a1, ..., an } (coeficientes reais do polinômio) e um vetor k = { x0, x1, ..., xk } (os valores de x
//para os quais se deseja calcular o polinômio).Armazene a resposta num vetor p = { p(x0), p(x1), ..., p(xk) } .


//8. Dado um vetor de n números reais, determinar os números que compõem o vetor e o número de vezes que cada um 
//deles ocorre no mesmo.
//Exemplo: v[8] = { ‐1.7,  3.0,  0.0,  1.5,  0.0, ‐1.7,  2.3, ‐1.7 }
//Saída: ‐1.7 ocorre 3 vezes

//3.0 ocorre 1 vez
//0.0 ocorre 2 vezes
//1.5 ocorre 1 vez
//2.3 ocorre 1 vez			FEITO NA MAIN



//9. Escreva a função criaAprovados que : ‐ recebe o número de alunos de uma turma, um vetor(de inteiros) com as matrículas dos alunos da turma, um vetor
//(de float) com as notas(vnota[k] é a nota do aluno com inscrição vinsc[k]) e o endereço de uma variável inteira
//onde deve ser devolvida a quantidade de alunos aprovados  ‐ retorna um novo vetor de inteiros, criado com alocação dinâmica com o tamanho exato necessário, apenas com as
//matrículas dos alunos aprovados, ou seja, aquele que têm nota >= 5.0.A função também devolve na variável cujo
//endereço foi recebido como parâmetro a quantidade de elementos do novo vetor(ou seja, de aprovados).Caso não
//exista nenhum aluno aprovado ou não seja possível alocar espaço para o novo vetor, a função retorna NULL.
//Faça uma função main para testar a função criada.
//OBSERVAÇÃO: Não esqueça de que na main() deve ser feita a chamada desta função e as respostas exibidas.Assim se
//não ocorreu nenhum problema, devem ser exibidos : a quantidade de elementos e os valores dos elementos do vetor
//retornado.Caso tenha ocorrido algum problema, deve ser exibida uma das mensagens abaixo(a mais apropriada) :
//	• “Nenhum aluno aprovado”, caso nenhum aluno tenha nota >= 5.0.
//	• “Nao foi possivel alocar espaco", caso não seja possível alocar memória para o novo vetor de aprovados. 


int* criaAprovados(int num_Alunos, int vetor_Matr[], float vetor_Nota[], int* qtd_aprovados)
{

	int qtd_Aprovados = 0;



	for (int i = 0; i < num_Alunos; i++)
	{

		if (vetor_Nota[i] >= 5.0)
		{

			qtd_Aprovados++;

		}
	}

	*qtd_aprovados = qtd_Aprovados;

	if (qtd_Aprovados == 0) {
		printf("Nenhum aluno foi aprovado");
		return NULL;
	}

	int* vetor_Aprovados = (int*)malloc(qtd_Aprovados * sizeof(int));

	
	if (vetor_Aprovados == NULL) {

		printf("Erro ao alocar memória");
		return NULL;
	}

	for (int i = 0; i < qtd_Aprovados; i++) 
	{
	
		if (vetor_Nota[i] >= 5.0) {

			vetor_Aprovados[i] = vetor_Matr[i];
		}
	}

	
	return vetor_Aprovados;

}


//---------------------------------------------------------------

////10) N foi possivel copiar o enunciado


int* valores_entre(int* vetor, int n, int min, int max, int* qtd)
{

	int cont_entre = 0;
	int* v_entre;
	int confirmado[] = { 0,0,0 };
	

	for (int i = 0; i < n; i++)
	{
		if (vetor[i] > min && vetor[i] < max) {

			cont_entre++;

		}
	}

	*qtd = cont_entre; //É isso que a questão pede no caso desse qtd?


	if (cont_entre == 0)
	{

		return NULL;
	}
	else
	{
		v_entre = (int*)malloc(cont_entre * (sizeof(int)));

		if (v_entre == NULL) {
			printf("Erro ao alocar memoria");
			return NULL;

		}
	}
	
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (vetor[i] > min && vetor[i] < max) {
			v_entre[index++] = vetor[i];//É possível ficar andando com o index para não deixar parado no local e andar junto com o for
		}
	}

	return v_entre;

}


int main(void)
{
	//1)
	//int num1 = 10;

	//int num2 = 5;

	//int soma;

	//int dif;

	//int produto;

	//returnOperacoes(num1, num2, &soma, &dif, &produto); //passando o endereço para a função

	//printf("Soma: %d\n", soma);

	//printf("Diferença: %d\n", dif);

	//printf("Produto: %d\n", produto);

	//return 0;

	//===============================================================================================================


	//2)
	/*float num = 2;
	float den = 0;

	float result;

	int possibilidade = retornaRazao(num, den, &result);

	if (possibilidade == 1) {

		printf("A razao eh possivel: %.2f", result);

	}
	else
	{
		printf("A razao NAO eh possivel");

	}

	return 0;*/


	//===============================================================================================================

	//3)
	/*int total_segundos = 45678;

	int hora;
	int min;
	int seg;

	converteHora(total_segundos, &hora, &min, &seg);

	printf("%d:%d:%d", hora, min, seg);*/


	//==============================================================================================================

	//4) 

	/*int lista_Valores[5] = { 2, 3, 4, 5, 6 };
	float media;
	int soma = 0;
	int qtd_Valores_Igual_Media = 0;

	for (int i = 0; i < 5; i++)
	{

		soma = soma + lista_Valores[i];

	}

	media = soma / 5;

	for (int i = 0; i < 5; i++)
	{
		if(lista_Valores[i] == (int)media) {

			qtd_Valores_Igual_Media++;

		}

	}

	if (qtd_Valores_Igual_Media != 0) {

		printf("Exitem %d valores na lista que sao iguais a media", qtd_Valores_Igual_Media);

	}
	else {
		printf("Nao existe nenhum valor na lista igual a media");
	}

	return 0;*/

	//=======================================================================================================================

	//5)

	/*int listaA [5] = { 1,2,3,4,5 };

	int listaB[5] = { 2,4,6,8,10 };

	int prod = 0;

	int soma = 0;

	for (int i = 0; i < 5; i++)
	{
		prod = listaA[i] * listaB[i];

		soma += prod;

	}

	printf("O produto escalar das listas A: { 1,2,3,4,5 } e B:{ 2,4,6,8,10 } eh = %d", soma);

	return 0;*/


	//=======================================================================================================================

	//6)

	/*int u[3] = { 1,2,3 };
	int v[3] = { 4,5,6 };

	int UxV[3] = { ((u[1] * v[2]) - (u[2] * v[1])), ((u[2] * v[0]) - (u[0] * v[2])), ((u[0] * v[1]) - (u[1] * v[0])) };

	printf("{ ");

	for(int i = 0; i < 3; i++) {


		printf("%d, ", UxV[i]);


	}
	printf("}");

	return 0;*/

	//=======================================================================================================================

	//8)
	//Existe uma outra forma de verificar verificar casos qunado o vetor repete os numeros varias vezes? Lógica difícil

	//Pensei em printar somente se os numeros fossem diferentes, mas seria considerado correto?

	//int n = 3;

	//int v[3] = { 1, 2, 2 };

	//int v_verf[3] = { 0, 0, 0 };

	//int conted[3] = { 0, 0, 0 };

	//for (int i = 0; i < n; i++) {

	//	if (conted[i] == 1) {

	//		continue; //Pula elementos já contados
	//	}

	//	for (int j = 0; j < n; j++) {

	//		if (v[i] == v[j]) {

	//			v_verf[i]++;
	//			conted[j] = 1; //Marca o elemento ja contado

	//		}

	//	}

	//}

	//for (int i = 0; i < n; i++) {

	//	if (v_verf[i] > 0) {
	//		printf("%d ocorre %d vezes\n", v[i], v_verf[i]);
	//	}

	//}

	//return 0;


	//

	//float v[3] = { 1, 2, 2 };
	//int v_verf[3] = { 0, 0, 0 };

	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		if (v[i] == v[j]) {
	//			v_verf[i]++;
	//		}
	//	}
	//}

	//for (int i = 0; i < 3; i++) {
	//	int already_printed = 0;
	//	for (int j = 0; j < i; j++) {
	//		if (v[i] == v[j]) {
	//			already_printed = 1;
	//			break;
	//		}
	//	}
	//	if (!already_printed) {
	//		printf("%d ocorre %d vezes\n", v[i], v_verf[i]);
	//	}
	//}

	//return 0;


//MELHOR RESOLUÇÃO PARA ESSE EXC (Tentar usar a logica do index exc 10) passar a casa if valor e igual, se não, manter a posição.
	//MELHOR RESOLUÇÃO PARA ESSE EXC (Tentar usar a logica do index exc 10) passar a casa if valor e igual, se não, manter a posição.
	int tamanho_lista = 8;

	float v[] = { -1.7, 3.0, 0.0, 1.5, 0.0, -1.7, 2.3, -1.7 };
	
	int ocorrido[8] = { 0, 0, 0, 0, 0, 0 ,0, 0 };

	for (int i = 0; i < tamanho_lista; i++)
	{

		if (ocorrido[i] == 1) {
			
			printf("%.2f ja foi verificado na posicao %d\n", v[i], i);
			continue;

		}


		int contador = 1;
		for (int j = i + 1; j < tamanho_lista; j++)
		{

			if (v[i] == v[j])
			{

				contador += 1;
				ocorrido[j] = 1;
				ocorrido[i] = 1; //linha so para testar se no final todas as posições ja foram visitadas

			}
		}

		printf("%.2f ocorre %d vezes\n\n", v[i], contador);

	}




	//=======================================================================================================================

	//9)
	//Faça uma função main para testar a função criada.
	//OBSERVAÇÃO: Não esqueça de que na main() deve ser feita a chamada desta função e as respostas exibidas.Assim se
	//não ocorreu nenhum problema, devem ser exibidos : a quantidade de elementos e os valores dos elementos do vetor
	//retornado.Caso tenha ocorrido algum problema, deve ser exibida uma das mensagens abaixo(a mais apropriada) :
	//	• “Nenhum aluno aprovado”, caso nenhum aluno tenha nota >= 5.0.
	//	• “Nao foi possivel alocar espaco", caso não seja possível alocar memória para o novo vetor de aprovados. 


	/*int num_Alunos = 2;

	int vetorMatricula[2] = { 123, 456};

	float vetorNota[2] = { 10.0, 8.0 };

	int qtd_aprovados = 0;

	int* vetorAprovados = criaAprovados(num_Alunos, vetorMatricula, vetorNota, &qtd_aprovados);

	if (qtd_aprovados == 0) {

		printf("Nenhum aluno foi aprovado");
		return 0;
	}

	printf("Quantidade de aprovados %d\n\n", qtd_aprovados);

	for (int i = 0; i < qtd_aprovados; i++) {

		printf("Matricula: %d\n", vetorAprovados[i]);

	}

	free(vetorAprovados);

	return 0;*/


	//=======================================================================================================================


	//10) N foi possivel copiar o enunciado

	/*int n = 5;
	int vetor[5] = {1,2,2,3,4};
	int qtd = 0;
	int min = 1;
	int max = 4;
	int* novo_vetor;



	novo_vetor = valores_entre(vetor, n, min, max, &qtd);

	printf("Qtd = %d\n\n", qtd);

	for (int i = 0; i < qtd; i++)
	{

		printf("Numero: %d\n", novo_vetor[i]);

	}


	return 0;*/





}