// Arquivos texto e binário 

// Uma editora possui 5 distribuidoras para os livros que publica. Crie um arquivo texto com títulos de livros, seguido 
// de barra (/), seguido da quantidade em estoque do livro em cada distribuidora, como mostra o exemplo abaixo: 


 //Dom Casmurro/ 10 5 120 15 32 
 //O Nome da Rosa/ 34 11 0 45 198 
 //Angustia/ 19 0 1 29 39  
 //A Menina Que Roubava Livros/ 12 72 46 55 19 
 //O Corpo Fala/ 0 65 50 19 30 
 //Viagem ao Mundo dos Taleban/ 3 98 0 112 45 
 //Quem Mexeu no Meu Queijo?/ 78 9 1 8 0 


// Implemente uma função para ler este arquivo e gerar dois outros arquivos: um primeiro arquivo texto com todos 
// os títulos dos livros (um por linha, na mesma ordem da entrada) e um segundo arquivo binário com todas as 
// quantidades em estoque em cada distribuidora (também na mesma ordem da entrada). Após gravar os arquivos 
// você deve fechá-los. 

// Em seguida, implemente outra função que abra e leia o arquivo texto com os títulos e o arquivo binário com as 
// quantidades nas distribuidoras e exiba na tela para cada livro, seu título, a quantidade média em estoque (com 2 
// casas decimais) e o total de livros em estoque em uma mesma linha.  

// Neste exercício, você vai ler e escrever arquivos textos.  

// Escreva um programa usando as funções descritas acima. Crie funções auxiliares para organizar sua solução. Não 
// se esqueça de liberar a memória alocada dinamicamente quando não for mais necessária. Os nomes dos arquivos 
// de entrada e saída devem ser escolhidos livremente.  

// Assuma que nenhum título excede 127 caracteres. Não use acentuação. Assuma também que não há erro de 
// formato no arquivo de entrada. Se ocorrer erro na abertura de arquivos, o programa deve exibir uma mensagem 
// informativa e ser abortado. 

// Dica: a leitura e escrita dos valores no arquivo binário devem ser feitas considerando sempre as cinco distribuidoras numa 
// única chamada de função fread ou fwrite; para tanto, as distribuidoras de cada livro da editora devem ser armazenadas em 
// vetores. 


//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//void geraArquivos(char* nomeArq, char* nomeArqSaidaEstoque, char* nomeArqSaidaTitulos); // Função que gera os arquivos.
//void verificaEleEstoque(char* nomeArqSaidaEstoque); // Função que verifica os Elementos do arquivo binário pois não eh possivel ver o arquivo,então deve-se printar pra ver se está correto.
//void retornaInfos(char* nomeArqSaidaTitulos, char* nomeArqSaidaEstoque);// Fudeu
//
//
//int main(void) {
//
//    char* nomeArqEntrada = "LivrosExcBin.txt";
//    char* nomeArqSaidaTitulos = "SaidaArqTitulos.txt";
//    char* nomeArqSaidaEstoque = "SaidaArqEstoque.dat";
//
//
//    geraArquivos(nomeArqEntrada, nomeArqSaidaEstoque, nomeArqSaidaTitulos);
//    verificaEleEstoque(nomeArqSaidaEstoque);
//    retornaInfos(nomeArqSaidaTitulos, nomeArqSaidaEstoque);
//
//
//    return 0;
//
//}
//
//
//
//void geraArquivos(char* nomeArq, char* nomeArqSaidaEstoque, char* nomeArqSaidaTitulos) {
//
//    FILE* arqEntrada;
//    FILE* arqSaidaTitulos;
//    FILE* arqSaidaEstoque;
//
//
//
//    arqEntrada = fopen(nomeArq, "r");
//
//    if (arqEntrada == NULL) {
//
//        printf("Erro na abertura do arquivo de entrada");
//
//        exit(1);
//
//    }
//
//
//    arqSaidaTitulos = fopen(nomeArqSaidaTitulos, "w");
//
//    if (arqSaidaTitulos == NULL) {
//
//        printf("Erro na abertura do arquivo de saida TITULOS");
//
//        exit(1);
//
//    }
//
//
//
//    arqSaidaEstoque = fopen(nomeArqSaidaEstoque, "wb");
//
//    if (arqSaidaEstoque == NULL) {
//
//        printf("Erro na abertura do arquivo de saida ESTOQUE");
//
//        exit(1);
//
//    }
//
//
//    //--------------------------------------------------------
//
//    char titulo[128];
//    int estoque[5];
//
//
//    while (fscanf(arqEntrada, " %[^/]/ %d %d %d %d %d", titulo, &estoque[0], &estoque[1], &estoque[2], &estoque[3], &estoque[4]) == 6) { 
//
//        fprintf(arqSaidaTitulos, "%s\n", titulo);
//
//        fwrite(estoque, sizeof(int), 5, arqSaidaEstoque);
//    }
//
//
//    fclose(arqEntrada);
//    fclose(arqSaidaTitulos);
//    fclose(arqSaidaEstoque);
//
//    return;
//}
//
////==================================================================================
//
//void verificaEleEstoque(char* nomeArqSaidaEstoque) {
//
//    FILE* arqEntrada;
//
//    arqEntrada = fopen(nomeArqSaidaEstoque, "rb");
//
//    int buff_Estoque[5];
//
//    while (fread(buff_Estoque, sizeof(int), 5, arqEntrada) == 5) {
//
//        for (int i = 0; i < 5; i++) {
//
//            printf("%d ", buff_Estoque[i]);
//
//        }
//        printf("\n\n");
//    }
//
//    fclose(arqEntrada);
//
//    return;
//}
//
////===================================================================================
//
//float soma(int* vInteiros) {
//
//    float soma = 0.0;
//
//    for (int i = 0; i < 5; i++) {
//
//        soma = soma + vInteiros[i];
//    }
//
//    return soma;
//
//}
//
//
//float mediaEstoque(int* vInteiros) {
//
//    return soma(vInteiros) / 5;
//
//    //não tem como ser diferente de 5 por que quando salvo o arqv bin todas as informações numéricas estão na mesma linha
//}
//
////==================================================================================
//
//
//
//void retornaInfos(char* nomeArqSaidaTitulos, char* nomeArqSaidaEstoque) {
//
//    FILE* arqEntradaTitulos;
//    FILE* arqEntradaEstoque;
//
//    arqEntradaTitulos = fopen(nomeArqSaidaTitulos, "r");
//    arqEntradaEstoque = fopen(nomeArqSaidaEstoque, "rb");
//
//
//    if (arqEntradaTitulos == NULL) {
//
//        printf("Erro na abertura do arquivo TITULOS");
//
//        exit(1);
//    }
//
//    if (arqEntradaEstoque == NULL) {
//
//        printf("Erro na abertura do arquivo ESTOQUE");
//
//        exit(1);
//    }
//
//    //-------------------------------------------------------------
//    //Preparando o vetor
//    //Parte Texto
//
//    char bufferTitulo[128];
//    char** vetorBufferTitulos;
//    int contTitulos;
//
//
//    contTitulos = 0;
//    while (fscanf(arqEntradaTitulos, " %[^\n]", bufferTitulo) == 1) { //contando a quantidade de titulos
//
//        contTitulos++;
//
//    }
//
//
//    rewind(arqEntradaTitulos);
//
//
//    vetorBufferTitulos = (char**)malloc(contTitulos * sizeof(char*));// alocando memória para o vetor de string
//
//    int i = 0;
//    while ((fscanf(arqEntradaTitulos, " %[^\n]", bufferTitulo)) == 1) { //adicionando as strings no vetor
//
//        vetorBufferTitulos[i] = (char*)malloc((strlen(bufferTitulo) + 1) * sizeof(char));
//
//        strcpy(vetorBufferTitulos[i], bufferTitulo);
//
//        i++;
//    }
//
//
//    rewind(arqEntradaTitulos);
//
//
//    //-------------------
//    //Parte Binário
//
//    int vetorEstoque[5];
//    int somaAtual;
//    float mediaAtual;
//
//    for (int i = 0; i < contTitulos; i++) {
//
//
//
//        fread(vetorEstoque, sizeof(int), 5, arqEntradaEstoque);
//
//        somaAtual = 0;
//        for (int i = 0; i < 5; i++) {
//
//            somaAtual += vetorEstoque[i];
//
//        }
//        mediaAtual = somaAtual / 5.0;
//
//        printf("%s --> A soma do estoque eh: %d e a media do estoque eh %.2f\n\n", vetorBufferTitulos[i], somaAtual, mediaAtual);
//    }
//    
//    return;
//}


//=================================================================================================================================================================

//Exercício arquivos texto e binário
//Considere um arquivo texto de entrada com nomes de pessoas, seguidos de dois pontos(:) e com a profissão
//logo após.Esse arquivo tem o número de registros disponibilizado na primeira linha.Por exemplo :
//
//3
//ada lovelace : escritora
//aaa ccc e ddd : engenheiro
//xx yy de zz : medico
//
//Leia este arquivo e construa um vetor de strings do tipo “profissão nome”.Por exemplo, a primeira string é
//“escritora ada lovelace”.Todas as alocações devem ser dinâmicas.
//
//Escreva uma função auxiliar que recebe o ponteiro para o arquivo e retorna a string “profissão nome” alocada
//dinamicamente.Retorne NULL quando não mais conseguir ler nomes e profissões(o que vai acontecer no fim do arquivo).
//Use o fato de que essa função retorna NULL para controlar o loop de leitura de linhas na main.
//
//Use o vetor de strings em uma função que retorna o índice da string de maior comprimento.No caso acima,
//retorna o índice 1. Na main, imprima essa string. (no exemplo acima, imprime:
//engenheiro aaa ccc e ddd
//
//Grave um arquivo binário contendo o tamanho desta string maior e todos os caracteres desta string(não grave o \0).
//Depois faça um outro programa que lê este arquivo binário, monta a string e a imprime.


//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//
// //CABEÇALHO =================================================
//
//char* auxiliar(FILE* arqEntrada);
//int retornaIndicie(char** vetorProfNome, int totalLinhas, char* nome);
//void exibe_Bin(char* nomeArqEntrada);
//
////CABEÇALHO =================================================
//
//
//
//int main(void) {
//
//	char* nomeArqv = "excArqvBin_nomeprof.txt";
//	char* nomeArqvBin = "excArqvBin_infostr.dat";
//	int totalLinhas;
//	char** vetorProfNome;
//	char* strAux;
//	int tamMaiorStr;
//	int i;
//
//	FILE* arqEntrada;
//
//	arqEntrada = fopen(nomeArqv, "r");
//
//	if (arqEntrada == NULL) {
//
//		printf("Erro ao abrir o arquivo de entrada");
//
//		exit(-1);
//
//	}
//
//	FILE* arqEntradaBin;
//
//	arqEntradaBin = fopen(nomeArqvBin, "wb");
//
//	if (arqEntradaBin == NULL) {
//
//		printf("Erro ao abrir o arquivo de entrada binario");
//
//		exit(-1);
//
//	}
//		
//	/*totalLinhas;*/
//	fscanf(arqEntrada, "%d", &totalLinhas);
//	
//
//	vetorProfNome = (char**)malloc((totalLinhas) * sizeof(char*));
//
//	if (vetorProfNome == NULL) {
//
//		printf("Erro ao aolcar memória");
//		return NULL;
//
//	}
//
//	
//	strAux = auxiliar(arqEntrada);
//	//printf("%s\n", strAux);
//	i = 0;
//	while (strAux != NULL) {
//
//		vetorProfNome[i] = strAux;
//
//
//		strAux = auxiliar(arqEntrada);
//		
//		i++;
//	}
//
//	for (i = 0; i < totalLinhas; i++) {
//
//		printf("%s\n\n", vetorProfNome[i]);
//
//	}
//
//	int indicie_Maior_str = retornaIndicie(vetorProfNome, totalLinhas, nome);
//
//	printf("%s\n", nome);
//
//	printf("A maior string eh: %s/ Esta na posicao: %d \n", vetorProfNome[indicie_Maior_str], indicie_Maior_str + 1);
//
//	fclose(arqEntrada);
//	//free(vetorProfNome); o que isso faz exatamente
//
//	//tamMaiorStr = (strlen(vetorProfNome[indicie_Maior_str])-1);
//
//	//fwrite(&tamMaiorStr, sizeof(int), 1, arqEntradaBin);
//
//	//exibe_Bin(nomeArqvBin);
//
//	//for (i = 0; i < tamMaiorStr;i++) {
//
//	//	fwrite(vetorProfNome[indicie_Maior_str], sizeof(char), 1, arqEntradaBin);
//
//	//}
//
//}
//
//
//char* auxiliar(FILE* arqEntrada) {
//
//
//	char nome[128];
//	char profissao[128];
//
//	char* strProfNome;
//
//	if (fscanf(arqEntrada, " %[^:]: %[^\n]", nome, profissao) == 2) {
//
//
//		strProfNome = (char*)malloc((strlen(nome) + strlen(profissao) + 2) * sizeof(char));
//
//		if (strProfNome == NULL) {
//
//			printf("Erro ao alocar memoria para string\n");
//			exit(-1);
//		}
//
//		strcpy(strProfNome, profissao);
//		strcat(strProfNome, " ");
//		strcat(strProfNome, nome);
//	}
//	else {
//		return NULL;
//
//	}
//
//	return strProfNome;
//}
//
//
////Use o vetor de strings em uma função que retorna o índice da string de maior comprimento.No caso acima,
////retorna o índice 1. Na main, imprima essa string. (no exemplo acima, imprime:
////engenheiro aaa ccc e ddd
//
//int retornaIndicie(char** vetorProfNome, int totalLinhas, char *nome) {
//
//
//	int i;
//	int pos = 0;
//	char* maiorStr = vetorProfNome[0];
//	for (i = 0;i < totalLinhas;i++) {
//		
//		if (strlen(vetorProfNome[i]) > strlen(maiorStr)) {
//
//			maiorStr = vetorProfNome[i];
//			pos = i;
//
//		}
//	}
//
//	return pos;
//}
//
//void exibe_Bin(char* nomeArqEntrada) {
//
//	FILE* arqEntrada = fopen(nomeArqEntrada, "rb");
//
//	if (arqEntrada == NULL) {
//		printf("Erro ao abrir o arquivo binário na funcao exibebin.\n");
//		return;
//	}
//
//	int tamanho;
//	fread(&tamanho, sizeof(int), 1, arqEntrada); // Lê o tamanho da string
//	printf("Tamanho da maior string: %d\n", tamanho);
//
//	// Aloca memória para a string
//	char* maiorString = (char*)malloc(tamanho * sizeof(char) + 1); // +1 para o terminador nulo
//	if (maiorString == NULL) {
//		printf("Erro ao alocar memória para leitura da string\n");
//		fclose(arqEntrada);
//		return;
//	}
//
//	// Lê a string completa do arquivo binário
//	fread(maiorString, sizeof(char), tamanho, arqEntrada);
//	maiorString[tamanho] = '\0'; // Adiciona o terminador nulo
//
//	printf("Maior string lida do arquivo binário: %s\n", maiorString);
//
//	// Libera a memória alocada e fecha o arquivo
//	free(maiorString);
//	fclose(arqEntrada);
//}


//=================================================================================================================================================================

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct medidas
{

	float peso;
	float altura;

};
typedef struct medidas Medidas;


struct cliente
{
	
	char nome[81];
	int id;
	char genero;
	Medidas med;

};
typedef struct cliente Cliente;

typedef struct elemento Elemento;

struct elemento
{

	float imc;
	Elemento* prox;

};

//Cabeçalho======================

FILE* openFILE(const char* file, const char* mode);
float bodyMassIndex(Cliente c, int* status);
Elemento* lst_insere(Elemento* lst, float imc);
float mediaBMI(Elemento* lst, int* n);
void libera_e_fecha(Elemento* lst, FILE* arqv);


//Cabeçalho======================


int main(void) {

	int i;
	int n;
	int totalClientes;
	int status;
	
	float mediaIMC;
	float imc;

	char* nomeArq = "clientes_p2.dat";
	Cliente c;
	Elemento* p;
	Elemento* lst = NULL;

	FILE* arqEntrada = openFILE(nomeArq, "rb");

	fread(&totalClientes, sizeof(int), 1, arqEntrada);

	//Cliente* cs;
	//cs = (Cliente*)malloc(sizeof(Cliente) * totalClientes);
	//fread(cs, sizeof(Cliente), totalClientes, arqEntrada);

	
	int contAcimaPeso = 0;
	for (i = 0;i < totalClientes;i++) {

		fread(&c, sizeof(Cliente), 1, arqEntrada);
		imc = bodyMassIndex(c, &status);

		if (status == 0) {

			printf("Nome: %s / Id: %d / Genero: %c / Peso: %.2f / Altura: %.2f / IMC = %.2f/ --> ABAIXO DO PESO\n\n", c.nome, c.id,c.genero, c.med.peso, c.med.altura, imc);

		}
		else if (status == 1) {

			printf("Nome: %s / Id: %d / Genero: %c / Peso: %.2f / Altura: %.2f / IMC = %.2f/ --> ACIMA DO PESO\n\n", c.nome, c.id, c.genero, c.med.peso, c.med.altura, imc);
			contAcimaPeso++;
			lst = lst_insere(lst,imc);
		}
	}
	mediaIMC = mediaBMI(lst, &n);

	printf("\n%d pessoas ACIMA do peso\n", n);
	printf("A media do IMC das pessoas acima do peso eh %.2f\n\n", mediaIMC);
	
	libera_e_fecha(lst, arqEntrada);

}

//Funções=========================================================

FILE* openFILE(const char* file, const char* mode) {

	FILE* arqEntrada = fopen(file, mode);

	if (arqEntrada == NULL) {

		printf("Erro de abertura na entrada do arquivo de entrada");
		exit(-1);
	}
	return arqEntrada;
}

float bodyMassIndex(Cliente c, int* status) {

	float calculoIMC;

	calculoIMC = (c.med.peso) / pow(c.med.altura,2);

	if (calculoIMC < 25) {

		*status = 0;

	}
	else {

		*status = 1;

	}

	return calculoIMC;
}


Elemento* lst_insere(Elemento* lst, float imc) {

	Elemento* c = (Elemento*)malloc(sizeof(Elemento));
	if (c == NULL) {

		return NULL;

	}

	c->imc = imc;

	c->prox = lst;

	return c;
}


float mediaBMI(Elemento* lst, int* n) { //Não precisa usar esse ponteiro para n, qtd de pessoas, mas como faz????

	
	float somaIMC = 0.0;
	int contPessoas = 0;

	Elemento* c;
	for (c = lst; c != NULL; c=c->prox) {

		somaIMC += c->imc;
		contPessoas++;

	}
	*n = contPessoas;

	 return somaIMC / contPessoas; //Problema com a media.
}

void libera_e_fecha(Elemento* lst, FILE* arqv) {

	Elemento* c;

	while(lst!=NULL) {
		
		c = lst;
		lst = lst->prox;

		free(c);


	}

	fclose(arqv);
}

