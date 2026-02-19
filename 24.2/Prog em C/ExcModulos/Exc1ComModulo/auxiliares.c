#include <stdio.h>

void situacao_aluno(float media) {

	if (media >= 5.0) {

		printf("Aprovado");

	}
	else if (media < 3.0) {

		printf("Reprovado");

	}
	else if (media >= 3.0 && media < 5.0) {

		printf("Em final");

	}

	return;
}


void parabes_aluno(float media) {

	if (media > 9.0) {

		printf("Parebens!!!!");


	}

}