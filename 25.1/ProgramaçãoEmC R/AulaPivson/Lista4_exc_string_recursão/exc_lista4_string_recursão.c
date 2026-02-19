#include <stdio.h>
#include <string.h>
#include <stdlib.h>







//Funções=======================

//1) Escreva a função contaB, que recebe uma cadeia e retorna (devolve) 2 valores: o número de ´b´s  e o número de 
//´B´s.
//Por exemplo :
//Cadeia recebida : “Barbudinho bonito”.Tem 1 ‘B’ e 2 ‘b’
//Escreva o programa completo para testar a sua função.

void contaB(char* palavra, int* cont_b_zinho, int* cont_b_zao) {
	
	int tamanhoPalavra = strlen(palavra);

	for (int i = 0; i < tamanhoPalavra; i++)
	{

		if (palavra[i] == 'b') {

			(*cont_b_zinho)++;

		}
		else if (palavra[i] == 'B')
		{

			(*cont_b_zao)++;
			palavra[i] = 'A';

		}
	}
}

//2)  Escreva a função contaNaoLetras, obrigatoriamente na forma RECURSIVA, que: 
// recebe uma cadeia de caracteres
// retorna o número de caracteres que não são letras(nem maiúsculas, nem minúsculas).A função retorna 0 no
//caso de cadeia vazia.
//Por exemplo : função retorna 4 para "T@ablet281" e 1 para "CaLLIOPE9".
//IMPORTANTE : A função recursiva tem que obrigatoriamente fazer uso da definição recursiva de cadeia, isto é, uma
//cadeia de caracteres é :
// a cadeia de caracteres vazia; ou
// um caractere seguido de uma cadeia de caracteres.

int contaNaoLetras_Rec(char* string)
{
	if (*string == '\0') {

		return 0;
	}
	
	
	if (!(*string >= 'A' && *string <= 'Z') && !(*string >= 'a' && *string <= 'z')) { //tem que ser *string pois é um ponteiro que aponta para o primeiro caractere da cadeia de caracteres
		return 1 + contaNaoLetras_Rec(string+1); // Conta e pula uma letra da string

	}
	else {
		contaNaoLetras_Rec(string + 1);
	}
}

int contaNaoLetras_NaoRec(char* string)
{
	int contNaoLetras = 0;

	int tamanhoPalavra = strlen(string);

	if (string == NULL) {

		return 0;
	}

	for (int i = 0; i < tamanhoPalavra; i++)
	{

		if (!(string[i] >= 'A' && string[i] <= 'Z') && !(string[i] >= 'a' && string[i] <= 'z')) {

			contNaoLetras++;

		}

	}
	
	return contNaoLetras;
}


//3) Escreva uma função recursiva para procurar um caractere em uma cadeia de caracteres. Caso o caractere seja 
//encontrado, a função deve retornar 1, caso contrário, deve retornar 0.
//int busca(char* str, char c);



int busca(char* str, char c) {

	if (str == NULL) {
		return 0;  // or handle the error as needed
	}


	if (*str == c) {

		return 1;
	}
	else if (*str == '\0') {

		return 0;

	}
	else {

		busca(str + 1, c);

	}
}


//4) Implemente uma função recursiva para substituir todas as ocorrências de letras minúsculas na cadeia pela 
//equivalente em maiúsculo, modificando a palavra original.
//void maiúsculo(char* str, char c);


void maiusculo(char* str, char c) {

	if (*str == '\0') {

		return;
	}
	else if (*str == c){

		*str = toupper(*str); //Nesse caso, dentro da função to upper é necessário que passo *str que refere-se ao coteúdo de onde a cadeia de caracteres está apontadno!
		maiusculo(str + 1, c);

	}
	else {
		maiusculo(str + 1, c);
	}


}



//5) Feita na main;

//função so para deixar mais bonito
int len(char* str) {

	int cont_caractere = 0;

	int i = 0;
	while (str[i] != '\0') {
		
		cont_caractere++;
		i++;

	}

	return cont_caractere;
}


//6) feita na main

void removeAB(char* str) {

	int tamanho_str = strlen(str);

	char* nova_str = (char*)malloc(((tamanho_str + 1) * sizeof(char)));;

	int j = 0;

	for (int i = 0; i < tamanho_str; i++)
	{

		if ((str[i] == 'A' && str[i + 1] == 'B') || (str[i] == 'a' && str[i + 1] == 'b') || (str[i] == 'a' && str[i + 1] == 'B') || (str[i] == 'A' && str[i + 1] == 'b'))
		{

			i++;

		}
		else {
			nova_str[j++] = str[i];
		}
	}
	nova_str[j] = '\0';

	strcpy(str, nova_str);

	free(nova_str);

}



//==============================

//7) Generalizar a função do exercício anterior  para manipular duas cadeias quaisquer. Ou seja, a subcadeia que se 
// pretende retirar também é passada como parâmetro da função.

//cABra


void remove_sub_cadeia(char* str, char* sub_cadeia) {

	int tamanho_str = strlen(str);

	int tamanho_sub_cadeia = strlen(sub_cadeia);

	char* nova_str = (char*)malloc(((tamanho_str + 1) * sizeof(char)));

	int* array_verf_pos = (int*)malloc(tamanho_str * sizeof(int));



	if (nova_str == NULL) {
		
		printf("Erro ao alocar memoria para nova str");
		return;
	}

	int j = 0;
	for (int i = 0; i < tamanho_str; i++)
	{

		if (j == tamanho_sub_cadeia)
		{
			j = 0;
		}

		if (str[i] == sub_cadeia[j]) {

			j++;
			array_verf_pos[i] = 1;

			

		}
		else
		{

			array_verf_pos[i] = 0;

		}

	}


	int k = 0;
	for (int i = 0; i < tamanho_str; i++)
	{

		if (array_verf_pos[i] == 0) {

			nova_str[k] = str[i];
			k++;

		}


	}

	nova_str[k] = '\0';

	strcpy(str, nova_str);

	free(array_verf_pos);


}

////Solução chat
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//void remove_sub_cadeia(char* str, const char* sub_cadeia) {
//	int tamanho_str = strlen(str);
//	int tamanho_sub_cadeia = strlen(sub_cadeia);
//	char* nova_str = (char*)malloc((tamanho_str + 1) * sizeof(char)); // Aloca memória para a nova string
//	if (nova_str == NULL) {
//		printf("Erro ao alocar memoria para nova_str\n");
//		return;
//	}
//
//	int j = 0;
//	for (int i = 0; i < tamanho_str; i++) {
//		int k = 0;
//		// Verifica se a subcadeia está presente na posição atual
//		while (k < tamanho_sub_cadeia && str[i + k] == sub_cadeia[k]) {
//			k++;
//		}
//		// Se a subcadeia foi encontrada, pula os caracteres
//		if (k == tamanho_sub_cadeia) {
//			i += tamanho_sub_cadeia - 1; // Pula a subcadeia
//		}
//		else {
//			nova_str[j++] = str[i]; // Copia o caractere para a nova string
//		}
//	}
//	nova_str[j] = '\0'; // Termina a nova string com o caractere nulo
//
//	// Copia a nova string de volta para a string original
//	strcpy(str, nova_str);
//	free(nova_str); // Libera a memória alocada
//}
//
//int main(void) {
//	char str[] = "cABraABAB";
//	char sub_cadeia[] = "AB";
//
//	printf("String original: %s\n", str);
//	remove_sub_cadeia(str, sub_cadeia);
//	printf("String modificada: %s\n", str);
//
//	return 0;
//}


//===============================================


//8) Implemente uma função recursiva para verificar se uma determinada cadeia de caracteres é um palíndromo (i.e., se 
//é igual lida de trás pra frente).Se for, retorna 1, se não for, retorna 0. A função recebe também o comprimento da
//cadeia.
//int palindromo(char* str, int len);


// ARARA
int palindromo(char* str, int len)
{



	


}


//===============================================

//9) Desenvolver uma função que leia o nome completo de alguém, por exemplo.– João José da Silva – Maria B. Albuquerque
//e retorne uma outra cadeia com o nome na forma : – Silva, J.J.– Albuquerque, M.B.


//


//=====================================

//10) Escreva uma função recursiva que recebe um vetor de inteiros, seu tamanho e um valor x, e retorne o número de
//elementos do vetor que é maior que x.
//int maiorQueX(int n, int v[], int x);




//int maiorQueX(int n, int* v, int x)
//{
//
//	int* ultimoValor = v + (n - 1);
//
//
//	if (n == 1)// Se o tamanho for == 1 quer dizer que ele ta no ultimo numero;
//	{
//		if (*v > x)// Se está no ultimo numero, só baste adicionar mais 1 ao "contador"
//		{
//
//			return 1;
//		}
//		else
//		{
//
//			return 0;
//
//		}
//	}
//
//	if (*v > x) //Verfica se o elemnteo da vez é maior que o valor a ser verificado
//	{
//
//		return 1 + maiorQueX(n - 1, v + 1, x); // conta +1 e passa para o proximo elemento, então o n diminui 1 e o ENDEREÇO do vetor anda uma casa para frente;
//
//	}
//	else
//	{
//		return maiorQueX(n - 1, v + 1, x);
//	}
//
//}


//======================================

//11) Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um número natural N.Por
//exemplo, o dígito 2 ocorre 3 vezes em 762021192:
//int conta_dig(int n, int k)
//onde n é o número natural e k é o dígito(número entre 0 e 9) que se pretende procurar em n.

int conta_dig(int n, int k)
{
	if (n < 10)
	{
		if (k == n) {
			return 1;
		}

		return 0;
	
	}
	if (k == n / 10)
	{

		return 1 + conta_dig(n % 10, k);

	}
	else
	{
		return conta_dig(n % 10, k);
	}

}



//Funções=======================







int main(void) {

	//============================================

	//1)

	//o char* ocupa mais memória que char[]?

	//char palavra[] = "Barbudinho bonito"; //Recomendavel que se use a declarção de string assim, pois com char* ocupa mais memória que po char[] e também, char* não pode ser manipualdo

	//int cont_b_zinho = 0;
	//int cont_b_zao = 0;


	//contaB(palavra, &cont_b_zinho, &cont_b_zao); //por que não passao endereço de palavra?

	//printf("A quantidade de b minusculos eh %d\n\n", cont_b_zinho);

	//printf("A quantidade de B maiusuclos eh %d\n", cont_b_zao);



	//============================================

	//2)

	/*char string[] = "T@ablet281";

	int qtd_dif_letras_Nrec = contaNaoLetras_NaoRec(string);

	int qtd_dif_letras_Rec = contaNaoLetras_Rec(string);
	

	printf("Valor da funcao nao recursiva: %d\n", qtd_dif_letras_Nrec);

	printf("Valor da funcao recursiva: %d\n", qtd_dif_letras_Rec);



	return 0;*/


	//============================================

	//3)

	/*char string[] = "macaco";

	char caractere = 'c';

	int verf_caractere = busca(string, caractere);

	if (verf_caractere == 1) {

		printf("Caractere %c encontrado na palavra %s\n", caractere, string);

	}
	else if (verf_caractere == 0) {

		printf("Caractere %c NAO foi encontrado na palavra %s", caractere, string);

	}*/

	
	//============================================

	//4)


	/*char string[] = "macaco";

	char caractere = 'c';

	maiusculo(string, caractere);

	printf("%s", string);*/

	//============================================


	//5)  Escreva o programa em que duas cadeias sejam criadas. A primeira deve ser inicializada com  “TENTATIVA”, 
	//enquanto a segunda deve ser lida do teclado, ter no máximo 20 caracteres e pode conter brancos.Em seguida, exiba o
	//tamanho das duas cadeias.O tamanho de uma cadeia deve ser obtido utilizando a função comprimento feita por você,
	//que recebe uma cadeia e retorna o número de caracteres dessa cadeia('\0' não conta).
	//(OBS: para ler uma string com até 20 caracteres : scanf(" %20[^\n]", cadeia))


	/*char str1[] = "TENTANTIVA";

	char str2[21];

	printf("Digite uma string de ate 20 caracteres: ");
	scanf(" %20[^\n]", str2);

	printf("\n");

	int tamanho_str1 = len(str1);

	int tamanho_str2 = len(str2);


	printf("Tamanho da string 1 = %d\n\n", tamanho_str1);

	printf("Tamanho da string 2 = %d \n\n",tamanho_str2);
	*/

	//============================================

	//6) Desenvolver uma função para, dada uma cadeia de caracteres, alterá‐la para que sejam eliminadas 
	/*todas as ocorrências da sequência ‘AB’ na cadeia.*/

	/*char str[] = "ABracoABabABaB";

	printf("String original: %s\n", str);
	removeAB(str);
	printf("String modificada: %s\n", str);

	return 0;*/

	//============================================

	//7)

	/*char str[] = "cABABa";
	char sub_cadeia[] = "AB";

	printf("String original: %s\n", str);

	remove_sub_cadeia(str,sub_cadeia);

	printf("String modificada: %s\n", str);

	return 0;*/

	//==========================================

	//8) Dúvida

	//==========================================

	//9)

	/*char* nomeCompleto = "Maria B. Albuquerque";

	char* nomeMudado = retornaNomeSimplificado(nomeCompleto);

	printf("Nome alterado %s", nomeMudado);

	return 0;*/


	//==========================================
	

	//10)

	/*int tamanhoVetor = 4;
	int valorX = 2;
	
	int vetor[] = {1,2,3,3};

	int qtdValoresMaiorX;


	qtdValoresMaiorX = maiorQueX(tamanhoVetor, vetor , valorX);

	printf("A quantidade de valores maior que o numero %d eh: %d", valorX, qtdValoresMaiorX);*/

	//============================================

	//11)
	
	

	int numero = 123885;
	int k = 8;

	int conta_digito = conta_dig(numero, k);
	
	printf("%d", conta_digito);

	return 0;

}