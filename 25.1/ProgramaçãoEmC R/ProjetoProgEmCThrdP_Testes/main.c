#include <stdio.h>
#include <stdlib.h>

int somaElementoLisra(int lista[], int nmrDeQuestões) {

	int soma = 0;
	for (int i = 0; i < nmrDeQuestões; i++) {

		soma += lista[i];

	}

	return soma/nmrDeQuestões;

}



int main(void) 
{

	int i = 0;
	printf("Quantas notas voce quer registrar?: ");
	scanf("%d", &i);

	int* lista = (int*)malloc(i*sizeof(int));

	

	for (int j = 0; j < i; j++) {

		printf("Digite a nota %d: ",j + 1);
		scanf("%d", &lista[j]);
	
	}

	printf("A media das notas eh: %d", somaElementoLisra(lista, i));

	return 0;
}