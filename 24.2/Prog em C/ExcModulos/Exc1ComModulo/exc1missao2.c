//1.Faça um programa que leia a matrícula e as duas notas de um aluno, calcule a média aritmética e exiba
//a matrícula, a média, a situação(“aprovado”: média >= 5.0, “reprovado” : média < 3.0 ou “em final” : média
//	>= 3.0 e < 5.0) e a mensagem “parabéns”(caso a média do aluno seja acima de 9.0).O programa deverá
//	utilizar as seguintes funções, desenvolvidas em um arquivo “auxiliares.c”:
//a) para exibir a situação do aluno.Esta função deverá receber como parâmetro a média do aluno.
//b) para exibir a mensagem “parabéns”.Esta função deverá receber a média do aluno como
//parâmetro.


#include <stdio.h>
#include "auxiliares.h"

int main(void) {


	int matricula;
	float nota1, nota2, media;


	printf("Digite a sua matricula: ");
	scanf("%d", &matricula);


	printf("Digite a sua nota 1: ");
	scanf("%f", &nota1);


	printf("Digite a sua nota 2: ");
	scanf("%f", &nota2);


	media = (nota1 + nota2) / 2;


	printf("Sua media foi de %.1f e situacao e: ",media);
	situacao_aluno(media);
	parabes_aluno(media);


}