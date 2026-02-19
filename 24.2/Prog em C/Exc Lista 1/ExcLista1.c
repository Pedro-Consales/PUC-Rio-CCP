////EXC 2
//// Fa a um programa que leia o n mero de dias decorrido em um evento e exiba na tela o mesmo valor expresso em n mero de 
////semanas e n mero de dias.Por exemplo, se um usu rio fornecer o valor 19, o programa deve exibir :  2 semanas e 5 dias .
//
////#include <stdio.h>
//
////int main(void) {
//
//	//int diasEvento, semanas, dias;
//	//printf("Digite a quantidade de dias decorridos de um evento: ");
//	//scanf("%d", &diasEvento);
//
//	//semanas = diasEvento / 7;
//	//dias = diasEvento % 7;
//
//
//	//printf("O evento tem no total %d dias, que equivalem a %d semanas e %d dias", diasEvento, semanas, dias);
//
//	//return 0;
//
////}
//
//
//
////=====================================================================================================================================
//
//
//
//
//Exc3) 
////Fa a um programa que leia as duas notas de um aluno, calcula e imprime a sua m dia sabendo que a primeira nota tem peso
////3 e a segunda nota tem peso 7.
// 
//
//#include <stdio.h>
//
//float calcula_media(float n1, float n2) {
//
//	float media;
//	media = ((3 * n1) + (7 * n2)) / 10;
//	return media;
//
//}
// 
//float main(void) {
//
//
//	float n1, n2;
//
//
//	printf("Digite a nota 1 do aluno: ");
//	scanf("%f", &n1);
//
//
//	printf("Digite a nota 2 do aluno: ");
//	scanf("%f", &n2);
//
//
//	printf("A media do aluno e: %.2f ", calcula_media(n1,n2));
//
//	return 0;
//
//
//}
//
//======================================================================================================================================
//Exc4)
//Fa a um programa para obter a matr cula e a m dia de dois alunos e exibir a matr cula do aluno com a maior m dia.Considere que as m dias nunca s o iguais.
//#include <stdio.h>
//
//int main(void) {
//
//
//	int matricula1, matricula2;
//	float media1, media2;
//
//	printf("Digite a matricula e a media do aluno1: ");
//	scanf("%d%f", &matricula1, &media1);
//
//	printf("Digite a matricula e a media do aluno2:");
//	scanf("%d%f", &matricula2, &media2);
//
//
//	if (media1 > media2) {
//
//		printf("A matricula %d tem a maior media", matricula1);
//
//	}
//
//	else {
//
//		printf("A matricula %d tem a maior media",matricula2);
//
//	}
//
//
//
//	return 0;
//
//}
//
//
//============================================================================================================================================
//
// 
// EXC7) 7. Fa a um programa que receba dois n meros X e Y, sendo X < Y. Calcule e mostre a soma dos n meros 
//pares desse intervalo de n meros, incluindo os n meros digitados. - Entrada e Sa da 
// 
// 
//#include <stdio.h>
//
//int main(void) {
//
//	int x, y, sum;
//
//	x = 2;
//	y = 6;
//	sum = 0; 
//
//	while (x <= y) {
//
//		if (x % 2 == 0) {
//
//			sum += x;
//
//		}
//
//		x += 1;
//
//	}
//
//	x = 2;
//
//	printf("A soma dos numeros pares no intervalo %d .. %d e = %d",x, y, sum);
//
//
//
//	return 0;
//}
//
// 
// 
// ======================================================================================================================================
// 
// Exc8)  Refa a o programa anterior, agora sem considerar que necessariamente X<Y. Caso X>Y, considere o 
//intervalo como sendo de Y at  X. (N O SERIA IGUAL??????) - Entrada e Sa da
//
//
//
//#include <stdio.h>
//
//int main(void) {
//
//	int x, y, sum;
//
//	x = 2;
//	y = 6;
//	sum = 0;
//
//	while (x <= y) {
//
//		if (x % 2 == 0) {
//
//			sum += x;
//
//		}
//
//		x += 1;
//
//	}
//
//	x = 2;
//
//	printf("A soma dos numeros pares no intervalo %d .. %d e = %d", x, y, sum);
//
//
//
//	return 0;
//}
//
//========================================================================================================================================
//
// 
// Exc9)  Uma empresa para se tornar conhecida do p blico jovem, decidiu sortear brindes na entrada de uma festa. 
//Como n o h  brinde para todos, seriam premiados apenas os convidados cujo m s de anivers rio   divisor do
//dia do anivers rio.Fa a um programa em C que inicialmente leia a quantidade de brindes que ser o
//distribu dos.Em seguida, para cada convidado que ingressa na festa, o programa deve ler o dia e o m s do
//seu anivers rio.Se o convidado tem direito ao brinde, o programa deve exibir a mensagem  PARAB NS .
//Quando n o h  mais brindes para distribuir, o programa deve exibir a mensagem  PROMO  O
//ENCERRADA  e ser encerrado.
// 
// 
//
//
//#include <stdio.h>
//
//int main(void) {
//
//	int diaAnv, mesAnv;
//	int qtdBrindes, contBrindes;
//
//	printf("Digite a quantidade de brindes que serao distribuidos:");
//	scanf("%d", &qtdBrindes);
//
//
//	contBrindes = 0;
//	while (contBrindes < qtdBrindes) {
//
//		printf("Digite o dia do seu aniversario: ");
//		scanf("%d", &diaAnv);
//		printf("Digite o mes do seu aniversario: ");
//		scanf("%d", &mesAnv);
//
//		if (diaAnv % mesAnv == 0) {
//
//			printf("Parabens\n");
//			contBrindes += 1;
//		}
//
//	}
//
//	if (contBrindes == qtdBrindes) {
//
//		printf("Promocao encerrada, nao ha mais brindes");
//
//	}
//
//
//		return 0;
//
//	}
//
//=======================================================================================================================
//
// 10. Escreva um programa para ler os números de matrículas (como inteiros) dos alunos de um cursinho, as 
// notas dos seus trabalhos e exiba ao final a matrícula e a nota final do aluno (média das notas dos trabalhos). 
// O curso é personalizado, ou seja, cada aluno tem um conjunto de trabalhos diferente, inclusive em relação a 
// número de trabalhos. Seu programa deve: - ler a matrícula de um aluno - ler o número x de trabalhos desse aluno
// - ler as x notas do aluno, calculando a média - exibir a matrícula e média do aluno 
// A leitura de um valor de matrícula igual a 0 (ZERO) indica o final da entrada de dados. 
//
//#include <stdio.h>
//
//
//int main(void) {
//
//    int matricula, nTrabalhos, contTrabalhos;
//    int nota, soma;
//    float media;
//
//
//
//    printf("Digite a sua matricula: ");
//    scnaf("%d", &matricula);
//
//
//    while (matricula != 0) {
//
//
//        pritf("Digite a quantidade de trabalhos: ");
//        scnaf("%d", &nTrabalhos);
//
//        soma = 0;
//        contTrabalhos = 0;
//        while (contTrabalhos < nTrabalhos) {
//
//
//            printf("Digite a nota do trabalho %d: ", contTrabalhos + 1);
//            scanf("%d", &nota);
//
//            soma = soma + nota;
//            contTrabalhos += 1;
//        }
//
//        media = soma / nTrabalhos;
//
//        printf("O aluno de matricula %d, obteve uma media de %.1f pontos", matricula, media);
//
//        printf("Digite a sua matricula: ");
//        scnaf("%d", &matricula);
//
//    }
//
//    return 0;
//}
//11. Faça um programa que, para um número indeterminado de pessoas : leia a idade de cada uma, sendo que
//a idade 0 (zero)indica o fim da leitura e não deve ser considerada.A seguir calcule : -o número de pessoas; 
//-a idade média do grupo; -a menor idade e a maior idade.
//
//

//#include <stdio.h>
//
//int main(void) {
//
//	int idade, somaIdades;
//	float idadeMedia;
//	int menorIdade,maiorIdade;
//	int contPessoas;
//
//	contPessoas = 1;
//
//	printf("Digite a idade da pessoa %d: ",contPessoas);
//	scanf("%d", &idade);
//
//	somaIdades = 0;
//	maiorIdade = 0;
//	menorIdade = 0;
//	while(idade != 0) {
//
//		idadeMedia = somaIdades / contPessoas;
//
//		if (idade > maiorIdade) {
//
//			maiorIdade = idade;
//
//		}
//		else if (idade < maiorIdade) {
//
//			menorIdade = idade;
//
//		}
//
//		printf("Digite a idade da pessoas %d: ",contPessoas+1);
//		scanf("%d", &idade);
//
//		contPessoas += 1;
//
//	}
//
//	printf("A maior idade eh %d, a menor idade eh %d e a media das idades sao %.1f",maiorIdade,menorIdade,idadeMedia);
//
//	return 0;
//}

