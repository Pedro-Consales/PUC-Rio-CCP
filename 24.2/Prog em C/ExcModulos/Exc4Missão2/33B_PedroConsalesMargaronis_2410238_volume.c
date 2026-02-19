////Sabe - se que o volume de uma caixa de lados a, b e c é dado por Vcaixa = a x b x c e que o volume de
////um cilindro de raio r e altura h é dado por Vcilindro = ?hr2.Pede - se:
////a) Escreva uma função para calcular e retornar o volume de uma caixa de lados a, b e c.Esta função
////deverá receber como parâmetro os lados a, b e c.
////b) Escreva uma função para calcular e retornar o volume de um cilindro de raio r e altura h.Esta função
////deverá receber como parâmetro o raio e a altura.
////c) Usando as funções dos itens anteriores, e que devem estar desenvolvidas em um arquivo “auxiliares.c”,
////escreva um programa para calcular o volume de uma caixa com um furo cilíndrico, com as dimensões
////ilustradas na figura abaixo.
////O programa deve capturar do teclado os valores das 4 dimensões da peça e deve exibir o valor do volume
////calculado.
//
//
////Aluno: Pedro Consales Margaronis
////Matricula: 2410238
//
//
//
//
//#include <stdio.h>
//#include "auxiliaresVolume.h"
//
//int main(void) {
//
//	int raio,baseCaixa,alturaCaixa,larguraCaixa, alturaCilindro;
//
//	printf("Digite o comprimento da caixa em metros: ");
//	scanf("%d", &baseCaixa);
//
//	printf("Digite a altura da caixa em metros: ");
//	scanf("%d", &alturaCaixa);
//
//	printf("Digite a largura da caixa em metros: ");
//	scanf("%d", &larguraCaixa);
//
//	printf("\n");
//
//	printf("O volume da caixa e %d m^3 \n", retorna_volumeCaixa(baseCaixa, larguraCaixa, alturaCaixa));
//
//	printf("\n");
//
//	printf("Digite o raio do cilindro em metros: ");
//	scanf("%d", &raio);
//
//	printf("Digite a altura do cilindro em metros: ");
//	scanf("%d", &alturaCilindro);
//
//	printf("\n");
//
//	printf("O volume do cilindro e %d m^3\n", retorna_volumeCilindro(raio, alturaCilindro));
//
//	return 0;
//}