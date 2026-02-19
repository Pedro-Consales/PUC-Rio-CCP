// Exc 3) . Escreva o programa para ler dois números inteiros distintos (a e b) e exibir todos os números ímpares 
//nesse intervalo(incluindo a e b), do menor para o maior.Observe que não necessariamente o primeiro
//valor lido é menor do que o segundo valor lido.

#include <stdio.h>

int main(void) {


	int a, b, numeroAtual, maiorNumero;

	printf("Digite um numero interio a: ");
	scanf("%d", &a);

	printf("Digite um numero interio b: ");
	scanf("%d", &b);

	if (a < b) {

		numeroAtual = a;
		maiorNumero = b;

	}
	else {

		numeroAtual = b;
		maiorNumero = a;
	}
	
	while (numeroAtual != maiorNumero) {

		if (numeroAtual % 2 == 0) {

			numeroAtual = numeroAtual + 1;

		}

		else {  

            printf(numeroAtual);

			numeroAtual = numeroAtual + 1;

		}


	}
	return 0;

}
