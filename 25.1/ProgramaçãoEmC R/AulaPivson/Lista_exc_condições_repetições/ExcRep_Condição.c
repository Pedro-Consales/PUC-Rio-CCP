#include <stdio.h>
#include <math.h>

void ExibeSituacao(float media) {

	if (media >= 5.0) {
		printf("Aprovado! ");
	}
	else if (media < 3) {
		printf("Reprovado! ");
	}
	else if (media >= 3.0 && media < 5.0) {
		printf("Em final! ");
	}

	return;
}

void ExibeParabens(float media) {

	if (media > 9.0) {
		printf("Parabens, sua media eh PICA PRA CARALHO!");
	}

	return;

}


int main(void)
{

	//1. Faça um programa que obtenha o dia de retirada e o dia da entrega de um livro da biblioteca (ambos no 
	//mesmo mês) e informe quantos dias o livro ficou emprestado.


	/*int dia_retirada, dia_entrega, dias_emprestado;


	printf("Digite o dia de retirada do livro: ");
	scanf("%d", &dia_retirada);


	printf("\nDigite o dia de entrega do livro: ");
	scanf("%d", &dia_entrega);

	dias_emprestado = dia_entrega - dia_retirada;

	printf("\nO livro foi emprestado por %d dias.\n", dias_emprestado);*/

	//-------------------------------------------------------------------------------------------------------------------------------


	//2. . Faça um programa que leia o número de dias decorrido em um evento e exiba na tela o mesmo valor 
	/*expresso em números de semanas e número de dias.Por exemplo, se um usuário fornecer o valor 19, o
		programa deve exibir : “2 semanas e 5 dias”.*/


	/*int dias = 0;
	int semanas;
	int diasRestantes;

	printf("Quantos dias de evento?: ");
	scanf("%d", &dias);

	semanas = dias / 7;

	diasRestantes = dias % 7;

	printf("%d semanas e %d dias", semanas, diasRestantes);


	return 0;*/

//-------------------------------------------------------------------------------------------------------

	/*3. Faça um programa que leia as duas notas de um aluno, calcula e imprime a sua média sabendo que a
			primeira nota tem peso 3 e a segunda nota tem peso 7.*/

	/*float nota1, nota2;
	float media;


	printf("Digite a nota1: ");
	scanf("%f", &nota1);

	printf("Digite a nota2: ");
	scanf("%f", &nota2);

	media = (((nota1 * 3) + (nota2 * 7)) / 9);

	printf("A media final do aluno eh: %.2f", media);

	return 0;*/

	//-------------------------------------------------------------------------------------------------------

	/*4. Faça um programa que calcule e mostre a área e o perímetro de uma sala retangular cujas medidas são
				fornecidas pelo usuário.*/

	/*double altura, comprimento;
	double area, perimetro;


	printf("Informe a altura da sala: ");
	scanf("%lf", &altura);

	printf("Informe o comprimento da sala: ");
	scanf("%lf", &comprimento);

	area = altura * comprimento;
	perimetro = (altura * 2) + (comprimento * 2);
	printf("\n A area da sala sera de: %.2f metros e o perimetro sera de: %.2f metros", area, perimetro);

	return 0;*/

	//-------------------------------------------------------------------------------------------------------------

	/*5. Faça um programa que leia dois números e um operador(caracter ‘ + ’, ‘ - ’, ‘ * ’ ou ‘ / ’) e realize a operação
					correspondente entre os operandos dados.*/

	/*float n1, n2;
	float resultado = 0;
	char operador;

	printf("Primeiro Numero: ");
	scanf("%f", &n1);

	printf("\n");

	printf("Digite a operação ( + ), ( - ), ( * ) ou ( / ): ");
	scanf(" %c", &operador);

	printf("\n");

	printf("Segundo Numero;");
	scanf("%f", &n2);

	printf("\n");

	if (operador == '+') {

		resultado = n1 + n2;

	}
	else if (operador == '-') {
		resultado = n1 - n2;
	}
	else if (operador == '*') {
		resultado = n1 * n2;
	}
	else if (operador == '/') {
		resultado = n1 / n2;

	}
	else {
		printf("Operador invalido");
	}

	printf("Seu resultado eh: %.2f", resultado);
	
	return 0;*/

	//-------------------------------------------------------------------------------------------------------------

//6. Faça um programa que leia a matrícula e as duas notas de um aluno, calcule a média aritmética e exiba a
//	matrícula, a média, a situação(“aprovado”: média >= 5.0, “reprovado” : média < 3.0 ou “em final” : média
//	>= 3.0 e < 5.0) e a mensagem “parabéns”(caso a média do aluno seja acima de 9.0).O programa deverá
//	utilizar as seguintes funções :
//	a) para exibir a situação do aluno.Esta função deverá receber como parâmetro a média do aluno.
//	b) para exibir a mensagem “parabéns”.Esta função deverá receber a média do aluno como parâmetro.


	

	/*int matricula;
	float nota1, nota2, media;


	printf("Digite a matricula: ");
	scanf("%d", &matricula);

	printf("\n");

	printf("Digite a nota1: ");
	scanf("%f", &nota1);

	printf("\n");

	printf("Digite a nota2: ");
	scanf("%f", &nota2);

	printf("\n");


	media = (nota1 + nota2) / 2;


	printf("Matricula: %d\n", matricula);

	printf("Media: %.2f\n", media);

	ExibeSituacao(media);

	ExibeParabens(media);*/


//-------------------------------------------------------------------------------------------------------------

//7. Faça um programa que receba dois números X e Y, sendo X < Y.Calcule e mostre a soma dos números
//	pares desse intervalo de números, incluindo os números digitados.

	/*int x;
	int X, Y;
	int soma = 0;
	
	printf("**************Voce ira digitar dois valores fixos, X e Y, tais que X tem que ser menor do que o Y!**************\n\n\n");

	printf("Digite o valor de X: ");
	scanf("%d", &X);

	x = X;

	printf("\n");

	printf("Digite o valor de Y: ");
	scanf("%d", &Y);

	if (Y < X) {

		printf("X precisa ser menor do que Y, invalido!");

		return 0;
	}



	for (int i = 0; i < Y; i++) {

		if (X % 2 == 0) {
			
			soma = soma + X;

		}
		X+=1;
	}

	printf("A soma dos numeros pares de X= %d e Y=%d eh: %d", x, Y, soma);


	return 0;*/


//-----------------------------------------------------------------------------

//8. Refaça o programa anterior, agora sem considerar que necessariamente X<Y.Caso X>Y, considere o
//intervalo como sendo de Y até X.


	/*int x_buffer, y_buffer;
	int X, Y;
	int soma = 0;

	printf("Digite o valor de X: ");
	scanf("%d", &X);

	x_buffer = X;

	printf("\n");

	printf("Digite o valor de Y: ");
	scanf("%d", &Y);

	y_buffer = Y;

	if (X < Y) {

		for (int i = 0; i < Y; i++) {

			if (X % 2 == 0) {

				soma = soma + X;

			}
			X += 1;
		}

		printf("A soma dos numeros pares de X= %d e Y=%d eh: %d", x_buffer, Y, soma);

	}
	else {

		for (int i = 0; i < X; i++) {

			if (Y % 2 == 0) {

				soma = soma + Y;

			}
			Y += 1;
		}

		printf("A soma dos numeros pares de Y= %d e X= %d eh: %d", y_buffer, X, soma);

	}
	

	return 0;*/


//-----------------------------------------------------------------------------------------

//9. Uma empresa para se tornar conhecida do público jovem, decidiu sortear brindes na entrada de uma festa.
//Como não há brinde para todos, seriam premiados apenas os convidados cujo mês de aniversário é divisor do
//dia do aniversário.Faça um programa em C que inicialmente leia a quantidade de brindes que serão
//distribuídos.Em seguida, para cada convidado que ingressa na festa, o programa deve ler o dia e o mês do
//seu aniversário.Se o convidado tem direito ao brinde, o programa deve exibir a mensagem “PARABÉNS”.
//Quando não há mais brindes para distribuir, o programa deve exibir a mensagem “PROMOÇÃO
//ENCERRADA” e ser encerrado.

	/*int qtdBrindes;
	int diaNasc;
	int mesNasc;

	printf("Informe a quantidade de brindes disponiveis: ");
	scanf("%d", &qtdBrindes);

	printf("\n");

	while(qtdBrindes != 0) {

		printf("Informe o dia do seu nascimento: ");
		scanf("%d", &diaNasc);

		printf("\n");

		printf("Informe o mes do seu nascimento: ");
		scanf("%d", &mesNasc);

		printf("\n");

		if (diaNasc % mesNasc == 0) {

			qtdBrindes -= 1;
			printf("Parabens voce ganhou um presente! :) --> Temos %d presentes restantes.\n\n", qtdBrindes);
		}
		else {

			printf("Infelizmente voce nao cumpre as regras para ganhar o presente :(\n\n");

		}
	}

	printf("Promocao encerrada!");

	return 0;*/


//10. Escreva um programa para ler os números de matrículas(como inteiros) dos alunos de um cursinho, as
//	notas dos seus trabalhos e exiba ao final a matrícula e a nota final do aluno(média das notas dos trabalhos).
//	O curso é personalizado, ou seja, cada aluno tem um conjunto de trabalhos diferente, inclusive em relação a
//	número de trabalhos.Seu programa deve : -ler a matrícula de um aluno - ler o número x de trabalhos desse aluno - ler as x notas do aluno, calculando a média - exibir a matrícula e média do aluno
//	A leitura de um valor de matrícula igual a 0 (ZERO)indica o final da entrada de dados.

	/*int matricula;
	int qtdTrabalho;
	float nota;
	float media;
	float somaNotas = 0;

	printf("<---- Bem vindo ao resgistro de notas! Para sair do menu de contas, basta registrar uma matricula com o numero 0 ---->\n\n");

	printf("Digite a matricula do aluno: ");
	scanf("%d", &matricula);

	while (matricula != 0) {

		printf("\n");

		printf("Quantos trabalhos esse aluno fez: ");
		scanf("%d", &qtdTrabalho);

		printf("\n\n");

		for (int i = 0; i < qtdTrabalho; i++) {

			printf("Digite a nota do trabalho #%d desse aluno--> ", i + 1);
			scanf("%f", &nota);

			somaNotas = somaNotas + nota;

			printf("\n");

		}

		media = somaNotas / qtdTrabalho;

		printf("A media do aluno de matricula %d foi de %.2f pontos!", matricula, media);

		printf("\n\n");

		printf("-----------------------------------------------------------------------------------");

		printf("\n\n");

		printf("Digite a matricula do aluno: ");
		scanf("%d", &matricula);

		printf("\n");
	}

	printf("A entreda de alunos terminou! Obrigado por utilizar o programa");

	return 0;*/


//--------------------------------------------------------------------------------------------------------


//11. Faça um programa que, para um número indeterminado de pessoas : leia a idade de cada uma, sendo que
//a idade 0 (zero)indica o fim da leitura e não deve ser considerada.A seguir calcule : -o número de pessoas; 
//-a idade média do grupo; -a menor idade e a maior idade.


	int idade;
	int contPessoas = 0;
	int somaIdades = 0;
	int mediaIdade;
	int menorIdade;
	int maiorIdade;

	printf("Digite a idade %d: ", contPessoas +1);
	scanf("%d", &idade);

	printf("\n");

	menorIdade = idade;
	maiorIdade = idade;

	while (idade != 0) {

		contPessoas += 1;
		
		somaIdades += idade;

		if (menorIdade > idade) {
			
			menorIdade = idade;

		}
		
		if (maiorIdade < idade) {

			maiorIdade = idade;

		}

		printf("Digite a idade %d: ", contPessoas + 1);
		scanf("%d", &idade);

		printf("\n");

	}
	mediaIdade = somaIdades / contPessoas;

	printf("Sao %d pessoas\n", contPessoas);
	printf("A idade media dessas pessoas eh: %d\n", mediaIdade);
	printf("A menor Idade eh: %d\n", menorIdade);
	printf("A maior Idade eh: %d\n", maiorIdade);


}