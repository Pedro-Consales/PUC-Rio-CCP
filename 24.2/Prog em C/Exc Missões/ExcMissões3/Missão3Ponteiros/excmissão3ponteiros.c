//Faça um programa que :
//
//declare duas variáveis do tipo inteiro(a, b)
//
//declare duas variáveis do tipo  ponteiro para inteiro(pa, pb).
//
//faça com que as variáveis do tipo ponteiro apontem para as variáveis do tipo inteiro.
//
//leia os valores de a e de b através de pa e  pb
//
//imprima os valores de a e de b usando a e b.
//
//#include <stdio.h>
//
//int main(void) {
//
//	int a, b;
//	int *pa, *pb;
//
//	pa = &a;
//	pb = &b;
//
//	printf("Digite o valor de A: ");
//	scanf("%d", pa);
//
//	printf("Digite o valor de B: ");
//	scanf("%d", pb);
//
//	printf("O valor de A eh: %d", a);
//	printf("\nO valor de B eh: %d", b);
//
//
//
//}
//================================================================================================================================================
// 
// 
// 
//Crie as funções e protótipos necessários ao correto funcionamento do programa abaixo.Não é permitido alterar a função main().
//
//#include <stdio.h> 
//
//void le_dados(int *ptr) {
//
//	scanf("%d", ptr);
//
//}
//
//void maior(int num1, int num2, int *max) {
//
//	if (num1 > num2) {
//
//		*max = num1;
//
//	}
//	else {
//
//		*max = num2;
//
//	}
//}
//
//float calculos(int num1, int num2, int *soma) {
//
//	float media = (num1 + num2)/2;
//
//	*soma = (num1 + num2);
//
//	return media;
//
//}
//
//
//int main(void)
//
//{
//	int num1, num2, max, soma;
//
//	printf("Informe um numero inteiro");
//
//	le_dados(&num1); // captura um número do teclado 
//
//	printf("Informe outro numero inteiro");
//
//	le_dados(&num2);
//
//	maior(num1, num2, &max);  // armazena em Max o maior valor entre os fornecidos 
//
//	printf("O maior numero eh %d ", max);
//
//	printf("A media dos numeros eh %.1f ", calculos(num1, num2, &soma)); // obs 
//
//	printf("A soma dos numeros eh %d ", soma);
//
//	return 0;
//
//}
//================================================================================================================================================
// Uma loja que comercializa peças de automóvel possui as seguintes informações de cada peça: código e classificação da peça. As peças são classificadas de acordo com a tabela abaixo que não deverá ser lida: 

// Classificação     Quantidade mínima em estoque     Quantidade máxima em estoque 

// 1 						100 								120

// 2 						150 								180 

// 3						200									250 

// 4 						250 								300 



// Faça um programa para processar as 100 peças comercializadas. Para cada peça, o programa deverá ler suas informações (código e classificação) e 
// exibir o seu código, a quantidade mínima e a quantidade máxima em estoque. 

// Faça as seguintes funções: 

// função classe ( ) à recebe como parâmetros a classificação da peça e guarda as quantidades mínima e máxima em estoque nas variáveis cujos 
// endereços são fornecidos na chamada da função. 

// função leitura ( ) à obtenção dos dados de uma peça. A função irá guardar os dados nas variáveis cujos endereços são fornecidos na chamada da função. 

//#include <stdio.h>
//#define TOTpecas 100
//
//void classe(int classificacao, int* nMaxEstoque, int* nMinEstoque) {
//
//	if (classificacao == 1) {
//
//		*nMaxEstoque = 120;
//		*nMinEstoque = 100;
//	}
//	else if (classificacao == 2) {
//
//		*nMaxEstoque = 180;
//		*nMinEstoque = 150;
//	}
//	else if (classificacao == 3) {
//
//		*nMaxEstoque = 250;
//		*nMinEstoque = 200;
//	}
//	else if (classificacao == 4) {
//
//		*nMaxEstoque = 300;
//		*nMinEstoque = 250;
//	}
//
//}
//
//void leitura(int* ptrCodigoPeca, int* ptrClassificacao) {
//
//	printf("Digite o codigo da peca: ");
//	scanf("%d", ptrCodigoPeca);
//	printf("Digite a classificacao da peca: ");
//	scanf("%d", ptrClassificacao);
//}
//
//
//
//int main(void) {
//
//	int i;
//	int codigoPeca, classificacao;
//	int nMaxEstoque, nMinEstoque;
//
//
//	for (i = 0;i < TOTpecas;i++) {
//
//		leitura(&codigoPeca, &classificacao);
//		classe(classificacao, &nMaxEstoque, &nMinEstoque);
//		printf("O produto do codigo %d de calssificacao %d, possui estoque maximo de %d e estoque minimo de %d\n", codigoPeca, classificacao, nMaxEstoque, nMinEstoque);
//	}
//
//	return 0;
//}
//================================================================================================================================================

// Escreva uma função que receba  um  número  inteiro  representando a  quantidade total de segundos  e,  usando endereços de variáveis,  
// converta  a  quantidade  informada de  segundos  em  Horas,  Minutos  e  Segundos. Utilize o seguinte função protótipo: 

// void converteHora(int total_segundos, int *hora, int *min, int *seg); 

// Faça um programa que leia, para cada atleta, seu número de inscrição e tempo (em s) que levou para completar 	uma maratona, 
// exibindo-o no formato HH:MM:SS. Atleta com número de inscrição 0 indica fim dos dados. 

// No final, deve mostrar o tempo (no formato HH:MM:SS)  e o nº de inscrição do atleta que levou menos tempo  e o tempo (no formato HH:MM:SS) e 
// o nº de inscrição do atleta que levou mais tempo.  

// Obs: sabe-se que atletas com tempo superior a 36000s são desclassificados. 

#include <stdio.h>

void converterHora(int total_segundos, int* hora, int* min, int* seg) {

	int restante;

	*hora = total_segundos / 3600;
	restante = total_segundos % 3600;
	*min = restante / 60;
	*seg = restante % 60;

}



int main(void) {


	int menorTempo, maiorTempo, inscMenorTempo, inscMaiorTempo;
	int numDeinscricao, total_segundos;
	int hora, min, seg;
	printf("Digite seu numero de inscricao: ");
	scanf("%d", &numDeinscricao);

	menorTempo = 36001;
	maiorTempo = 0;
	inscMaiorTempo = 0;
	inscMenorTempo = 0;
	while (numDeinscricao != 0) {

		printf("Digite o tempo que levou para completar a maratona: ");
		scanf("%d", &total_segundos);

		if (total_segundos > maiorTempo) {

			maiorTempo = total_segundos;
			inscMaiorTempo = numDeinscricao;

		}
		if (total_segundos < menorTempo) {

			menorTempo = total_segundos;
			inscMenorTempo = numDeinscricao;

		}

		converterHora(total_segundos, &hora, &min, &seg);

		printf("O atelta de inscricao %d fez um tempo de %02d:%02d:%02d \n", numDeinscricao, hora, min, seg);

		if (total_segundos >= 36000) {

			printf("Seu tempo foi maior que 10 hroas, VOCE ESTA DESCLASSIFICADO!!");
			printf("Digite seu numero de inscricao: ");
			scanf("%d", &numDeinscricao);

		}
		else {

			printf("Digite seu numero de inscricao: ");
			scanf("%d", &numDeinscricao);

		}

	}

	converterHora(maiorTempo, &hora, &min, &seg);
	printf("O atleta de inscricao %d teve o maior tempo, totalizando %02d:%02d:%02d\n", inscMaiorTempo, hora, min, seg);

	converterHora(menorTempo, &hora, &min, &seg);
	printf("O atleta de inscricao %d teve o menor tempo, totalizando %02d:%02d:%02d\n", inscMenorTempo, hora, min, seg);


	return 0;


}