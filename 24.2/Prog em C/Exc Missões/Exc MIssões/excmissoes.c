////EXC 1) MISS�O1 DIA 14/08/2024 - Entrada e Sa�da
//// Fa�a um programa que leia o n�mero de dias decorrido em um evento e exiba na tela o mesmo valor expresso em n�mero de 
////semanas e n�mero de dias.Por exemplo, se um usu�rio fornecer o valor 19, o programa deve exibir : �2 semanas e 5 dias�.
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
//Exc2) MISS�O1 DIA 14/08/2024 - Entrada e Sa�da
////Fa�a um programa que leia as duas notas de um aluno, calcula e imprime a sua m�dia sabendo que a primeira nota tem peso
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



//Exc1) MISS�O 2 DIA 26/08/2024 - Condicional e Repeti��o
//Fa�a um programa para obter a matr�cula e a m�dia de dois alunos e exibir a matr�cula do aluno com a maior m�dia.Considere que as m�dias nunca s�o iguais.

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
//Exc 2)
// MISS�O 2 DIA 26/08/2024 - Condicional e Repeti��o
// Fa�a um programa para obter o estoque m�nimo de um produto e o estoque atual e exibir a 
// situa��o do produto: abaixo do estoque, no limite ou acima do estoque. 
//
//#include <stdio.h>
//
//
//int main(void) {
//
//	int estoqueMin, estoqueAt;
//
//
//	printf("Digite o estoque minimo:");
//	scanf("%d", &estoqueMin);
//
//
//	printf("Digite o estoque atual:");
//	scanf("%d", &estoqueAt);
//
//	if (estoqueAt > estoqueMin) {
//
//		printf("O produto esta acima do estoque minimo");
//
//	}
//	else if (estoqueAt == estoqueMin) {
//
//		printf("O produto esta no limite do estoque");
//
//	}
//
//	else {
//
//		printf("O produto esta abaixo do estoque minimo ");
//
//	}
//	return 0;
//
//
//}
//
//
//============================================================================================================================
 //
 //Exc3) MISS�O 2 DIA 26/08/2024 - Condicional e Repeti��o
 //Fa�a um programa para obter a nota de uma turma com 20 alunos e calcular a m�dia da turma. 
 //
//
//#include <stdio.h>
//#define alunos 20
//
//int main(void) {
//
//	
//	float media;
//	float soma = 0;
//	int cont;
//
//	for (cont = 0; cont < alunos; cont++) {
//		float nota;
//		printf("Digite a nota do aluno %d = ", cont + 1);
//		scanf("%f", &nota);
//		soma = soma + nota;
//
//	}
//	media = soma / alunos;
//
//
//	printf("A media da turma e igual a %.2f", media);
//
//	return 0;
//
//
// }
//
// 
// 
// ==========================================================================================================================
// 
// 
// 
// Exc 3) MISS�O 2 26/08/2024 - Condicional e Repeti��o
// Fa�a um programa para obter os sal�rios dos funcion�rios de uma empresa e exibir o total pago com sal�rios, bem como 
// o sal�rio m�dio desta empresa. (sal�rio com valor zero significa fim da entrada de dados.) 
//
//
//#include <stdio.h>
//
//
//int main(void) {
//
//	float media, soma, salario;
//	int func;
//	soma = 0;
//	func = 0;
//	printf("Digite o salario do funcio�rio %d: ", func + 1);
//
//	while (salario != 0) {
//		printf("%f", salario);
//		func += 1;
//		soma += salario;
//		printf("Digite o salario do funcio�rio %d: ", func + 1);
//		scanf("%f", &salario);
//
//	}
//
//	media = soma / func;
//
//	printf("O total gasto com salario foi %.1f e a media de salario foi %.1f", soma, media);
//
//
//	return 0;
//=========================================================================================================================================
//
// Exc1) MISS�O 2 28/08/2024 - Fun��o 
// Para realizar um debate sobre ao acesso a dados considerados sigilosos em campanhas pol�ticas,
// um professor de �tica resolveu agrupar seus 400 alunos em 3 grupos: o grupo �pr�, o grupo �contra� e o grupo �neutro�. 
// Para saber a qual grupo o aluno pertence, o professor aplicou um question�rio cujas respostas podem ser sim (1) ou n�o (0). 
//
// 
//Fa�a uma fun��o que recebe o n�mero de quest�es, capture do teclado as respostas de cada uma das quest�es de um aluno 
// e retorne a quantidade de respostas positivas.
//
//Obs: o aluno digita 1, quando concorda e 0 quando discorda da quest�o
//
//Prot�tipo : int contabiliza_respostas(int n)
//
//
//
//Fa�a um programa que inicialmente capture o n�mero de quest�es do question�rio.A seguir, para cada aluno da turma, 
// obtenha sua matr�cula e respostas(utilizando a fun��o do item a), e exiba a matr�cula com o nome de seu grupo de acordo com 
// o seguinte crit�rio :
//
//2 / 3 de respostas sim 	� grupo �pr�
//
//2 / 3 de respostas n�o 	� grupo �contra�
//
//Demais situa��es	� grupo �neutro�
//
//Obs.: Fa�a uma fun��o para exibir o nome do grupo de respostas.Esta fun��o recebe o n�mero de quest�es e a 
// quantidade de respostas SIM.A fun��o n�o recebe a matr�cula.
//
//
//#include <stdio.h>
//#define alunos 400
//
//int contabiliza_respostas(int nQuestoes) {
//
//
//	int i, resposta, contSim;
//
//	contSim = 0;
//
//	for (i = 0; i < nQuestoes; i += 1) {
//
//		printf("Digite a resposta sim(1) ou nao(2): ");
//		scanf("%d", &resposta);
//
//		if (resposta == 1) {
//
//			contSim += 1;
//		}
//
//	}
//
//	return contSim;
//
//}
//
//
//void exibeGrupo(int nQuestoes, int totSim) {
//
//	float perc;
//	perc = (float)totSim / nQuestoes;
//	
//	if (perc > (float)0.666) {
//
//		printf("Grupo pro.\n");
//	}
//	else if (perc < (float)0.333) {
//
//		printf("Grupo contra. \n");
//	}
//	else
//	{
//		printf("Grupo neutro. \n");
//	}
//	return;
//
//
//
//}
//
//
//
//
//
//int main(void) {
//
//
//
//	int x, nQuestoes, matricula, qtdSim;
//
//	printf("Digite o numero de questoes: ");
//	scanf("%d", &nQuestoes);
//
//	for (x = 0; x < alunos; x++) {
//
//		printf("Digite a matricula: ");
//		scanf("%d", &matricula);
//
//		qtdSim = contabiliza_respostas(nQuestoes);
//		printf("Aluno: %d + => ", matricula);
//		exibeGrupo(nQuestoes, qtdSim);
//
//
//	}
//
//
//
//	return 0;
//}
//
// =============================================================================================================================================
// 
// 
// EXC 2) MISS�O 2 28/08/2024 - Fun��o
// 
// A vigil�ncia sanit�ria do reino T�oT�oPr�ximo autua os supermercados visitados conforme o n�mero de 
// produtos fora da validade. Em toda esta quest�o, considere que cada data � representada por tr�s n�meros inteiros, 
// correspondentes a dia, m�s e ano, respectivamente. 
//
//Escreva uma fun��o produto_vencido, que recebe a data da visita e a data de validade do produto e 
// retorna 1 caso o produto esteja fora da validade ou 0, caso contr�rio.
//
//Escreva uma fun��o calcula_multa, que recebe a quantidade de produtos conferidos e a quantidade de produtos fora da validade,
// e retorna o valor da multa, de acordo com as seguintes regras :
//
//0, caso nenhum produto conferido esteja fora da validade;
//
//100, caso at� 10 % dos produtos conferidos estejam fora da validade;
//
//10.000, caso mais de 10 % e at� 30 % dos produtos conferidos estejam fora da validade; e
//
//100.000, caso mais de 30 % dos produtos conferidos estejam fora da validade.
//
//Fa�a um programa em C que inicialmente capture a data da visita ao supermercado.Em seguida, para cada produto conferido, 
// capture o c�digo do produto(um n�mero inteiro) e a data do seu vencimento, mostrando para cada produto se ele est� ou n�o na validade.
// A entrada de dados � finalizada quando for digitado um c�digo de produto negativo.Seu programa dever� ent�o calcular e exibir o valor 
// da multa, caso haja, ou informar que o supermercado est� isento de multas.
//
//Observa��o: Seu programa dever� utilizar as fun��es definidas nos dois primeiros itens desta quest�o.
// 
// 
// 
//
//#include <stdio.h>
//
//int produto_vencido(int dataVisita, int mesVisita, int anoVisita, int dataVal, int mesVal, int anoVal) {
//
//
//	if (anoVisita > anoVal) {
//
//		return 1;
//
//	}
//	else if (anoVisita = anoVal) {
//
//		if (mesVisita > mesVal) {
//
//			return 1;
//
//		}
//		else if (mesVisita == mesVal) {
//
//			if (dataVisita > dataVal) {
//
//				return 1;
//
//			}
//
//		}
//
//	}
//
//	return 0;
//
//}
//
//int calcula_multa(int produtosConf, int qtdProdutoFval) {
//
//	float multa, contaMulta;
//
//	contaMulta = qtdProdutoFval / produtosConf;
//
//	if (contaMulta == 0) {
//
//		multa = 0;
//
//	}
//	else if (contaMulta > 0 && contaMulta <= 0.10) {
//
//		multa = 10;
//
//	}
//	else if (contaMulta > 0.10 && contaMulta <= 0.30) {
//
//		multa = 10.000;
//
//	}
//	else if (contaMulta > 0.30) {
//
//		multa = 100.000;
//
//	}
//
//	return multa;
//
//}
//
//
//int main(void) {
//
//
//
//
//	int dataVisita, mesVisita, anoVisita;
//	int dataVal, mesVal, anoVal;
//	int codProduto, produtosConf, qtdProdutoFval;
//	/*int Val_InVal;*/
//	float /*multa,*/somaMulta;
//
//
//	/*Val_InVal = produto_vencido (dataVisita, mesVisita, anoVisita, dataVal, mesVal, anoVal);
//	multa = calcula_multa (produtosConf, qtdProdutoFval);*/
//
//	printf("Digite o dia da visita ao supermecado realizado pela vigilancia: ");
//	scanf("%d", &dataVisita);
//	printf("Digite o mes da visita ao supermecado realizado pela vigilancia: ");
//	scanf("%d", &mesVisita);
//	printf("Digite o ano da visita ao supermecado realizado pela vigilancia: ");
//	scanf("%d", &anoVisita);
//
//	printf("\n");
//
//
//	printf("Digite o codigo do produto: ");
//	scanf("%d", &codProduto);
//
//	qtdProdutoFval = 0;
//	produtosConf = 0;
//	somaMulta = 0;
//
//	while (codProduto >= 0) {
//
//		printf("Digite o dia de validade do produto: ");
//		scanf("%d", &dataVal);
//		printf("Digite o mes de validade do produto: ");
//		scanf("%d", &mesVal);
//		printf("Digite o ano de validade do produto: ");
//		scanf("%d", &anoVal);
//
//		produtosConf += 1;
//
//		if (produto_vencido(dataVisita, mesVisita, anoVisita, dataVal, mesVal, anoVal) == 1) {
//
//
//			printf("Seu produto de codigo %d esta fora da validade\n", codProduto);
//			qtdProdutoFval += 1;
//			somaMulta += calcula_multa(produtosConf, qtdProdutoFval);
//
//		}
//
//		printf("Digite o codigo do produto: ");
//		scanf("%d", &codProduto);
//
//	}
//
//	if (somaMulta == 0) {
//
//		printf("O estabelecimento esta isento de multas!");
//
//	}
//	else
//	{
//
//		printf("O estabelecimento tem um total de R$ %.3f em multa para pagar devido aos produtos fora da validade encontrados", somaMulta);
//
//
//	}
//
//
//}
//
// ====================================================================================================================================
//
// Exc1) Miss�o 2 02/09/24 - Exc com Modulo
// 
// 
// ====================================================================================================================================
// 
// Exc2) Miss�o 2 02/09/24 
// 
// 
// 2. Escreva um programa para ler os n�meros de matr�culas (como inteiros) dos alunos de um cursinho, 
//as notas dos seus trabalhos e exiba ao final a matr�cula e a nota final do aluno(m�dia das notas dos
//	trabalhos.O curso � personalizado, ou seja, cada aluno tem um conjunto de trabalhos diferente, inclusive
//	em rela��o a n�mero de trabalhos.Seu programa deve : -ler a matr�cula de um aluno - ler o n�mero x de trabalhos
// desse aluno - ler as x notas do aluno, calculando a m�dia - exibir a matr�cula e m�dia do aluno
//	A leitura de um valor de matr�cula igual a 0 (ZERO)indica o final da entrada de dados.
// 
//
//
//#include <stdio.h>
//
//
//int main(void) {
//
//
//	int matricula, nTrabalhos, contTrabalhos;
//	float somaNotaT,notaT, mediaT;
//
//	printf("Digite a matricula:  ");
//	scanf("%d", &matricula);
//
//	while (matricula != 0) {
//
//		printf("Digite a quantidade de trabalhos: ");
//		scanf("%d", &nTrabalhos);
//
//		somaNotaT = 0;
//		contTrabalhos = 0;
//		while (contTrabalhos < nTrabalhos) {
//
//			printf("Digite a nota do trabalho: ", contTrabalhos + 1);
//			scanf("%f", &notaT);
//			
//			contTrabalhos += 1;
//			somaNotaT += notaT;
//
//			
//
//
//		}
//		
//		mediaT = somaNotaT / nTrabalhos;
//
//		printf("O aluno de matricula %d obteve uma media de %.1f pontos nos trabalhos\n", matricula, mediaT);
//
//		printf("Digite a matricula:  ");
//		scanf("%d", &matricula);
//
//	}
//
//
//	
//
//	return 0;
//
//
//}
//
// 
// ====================================================================================================================================
//
// Corrigir Corrigir Corrigir 
// Exc 3) Missão 2 02/09/24 Escreva o programa para ler dois n�meros inteiros distintos (a e b) e exibir todos os n�meros �mpares 
//nesse intervalo(incluindo a e b), do menor para o maior.Observe que n�o necessariamente o primeiro
//valor lido � menor do que o segundo valor lido.
// 
// 
// 
//#include <stdio.h>
//
//int main(void) {
//
//
//	int a, b, numeroAtual, maiorNumero;
//
//	printf("Digite um numero interio a: ");
//	scanf("%d", &a);
//
//	printf("Digite um numero interio b: ");
//	scanf("%d", &b);
//
//	if (a < b) {
//
//		numeroAtual = a;
//		maiorNumero = b;
//
//	}
//	else {
//
//		numeroAtual = b;
//		maiorNumero = a;
//	}
//
//	while (numeroAtual != maiorNumero) {
//
//		if (numeroAtual % 2 == 0) {
//
//			numeroAtual = numeroAtual + 1;
//
//		}
//
//		else {
//
//			printf(numeroAtual);
//
//			numeroAtual = numeroAtual + 1;
//
//		}
//
//
//	}
//	return 0;
//
//}