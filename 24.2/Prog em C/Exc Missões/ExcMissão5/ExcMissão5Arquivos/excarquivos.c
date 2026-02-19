
//// Exercício arquivos texto e binário 
// 
// 
//// Considere um arquivo texto de entrada com nomes de pessoas, seguidos de dois pontos (:) e com a profissão 
//// logo após. Esse arquivo tem o número de registros disponibilizado na primeira linha. Por exemplo: ]
//
//// 3 
//// ada lovelace: escritora 
//// aaa ccc e ddd: engenheiro 
//// xx yy de zz: medico 
//
//// Leia este arquivo e construa um vetor de strings do tipo “profissão nome”. Por exemplo, a primeira string é 
//// “escritora ada lovelace”. Todas as alocações devem ser dinâmicas. 
//// Escreva uma função auxiliar que recebe o ponteiro para o arquivo e retorna a string “profissão nome” alocada 
//// dinamicamente. Retorne NULL quando não mais conseguir ler nomes e profissões (o que vai acontecer no 
//// fim do arquivo). Use o fato de que essa função retorna NULL para controlar o loop de leitura de linhas na 
//// main. 
//// Use o vetor de strings em uma função que retorna o índice da string de maior comprimento. No caso acima, 
//// retorna o índice 1. Na main, imprima essa string. (no exemplo acima, imprime:  
//// engenheiro aaa ccc e ddd 
//// Grave um arquivo binário contendo o tamanho desta string maior e todos os caracteres desta string (não 
//// grave o \0). 
//// Depois faça um outro programa que lê este arquivo binário, monta a string e a imprime.
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//char *aux(char* arquivo) {
//
//    char nome[81];
//    char profissao[81];
//    int qtdPessoas;
//    char** vString;
//
//
//    fscanf(arquivo, "%d\n", &qtdPessoas);
//
//    vString = (char**)malloc(qtdPessoas * sizeof(char*));
//
//
//    int i = 0;
//    int cont = 0;
//    while (i < qtdPessoas && (fscanf(arquivo, "%[^:]: %[^\n]\n", nome, profissao) == 2)) {// Até EOF "End of File" usado para quando não se sabe quantos elementos tem no file.
//
//        printf("Profissao:%s - Nome:%s\n", profissao, nome);
//
//        vString[i] = (char*)malloc((strlen(nome) + strlen(profissao) + 2) * sizeof(char);
//        vString[i] = strcpy(profissao);
//        vString[i] = strcat(" ");
//        vString[i] = strcat(nome);
//
//        i++;
//    }
//
//																							INCOMPLETO INCOMPLETO INCOMPLETO!!!
//
//    return 
//}
//
//
//int main(void) {
//
//
//    FILE* arqEntrada;
//
//    arqEntrada = fopen("C:\\Users\\pedro\\OneDrive\\PUC-RIO\\Período2\\Prog em C\\Exc Missões\\ExcMissão5\\nomesEprofissao.txt", "r");
//
//
//
//}

//=======================================================================================================================================================================


//EXC distibuidoraArqTextp


// Arquivos texto  

// Uma editora possui 5 distribuidoras para os livros que publica. Crie um arquivo texto com títulos de livros, seguido de barra (/), 
// seguido da quantidade em estoque do livro em cada distribuidora, como mostra o exemplo abaixo: 



// Dom Casmurro/ 10 5 120 15 32 

// O Nome da Rosa/ 34 11 0 45 198 

// Angustia/ 19 0 1 29 39  

// A Menina Que Roubava Livros/ 12 72 46 55 19 

// O Corpo Fala/ 0 65 50 19 30 

// Viagem ao Mundo dos Taleban/ 3 98 0 112 45 

// Quem Mexeu no Meu Queijo?/ 78 9 1 8 0 



// Implemente uma função para ler este arquivo e gerar dois outros arquivos: um primeiro arquivo texto com todos os títulos dos 
// livros (um por linha, na mesma ordem da entrada) e um segundo arquivo texto com todas as quantidades em estoque em cada distribuidora 
// (também na mesma ordem da entrada).
// Após gravar os arquivos você deve fechá-los. 



// Em seguida, implemente outra função que abra e leia o arquivo texto com os títulos e o arquivo com as quantidades nas distribuidoras
// e exiba na tela para cada livro,
//  seu título, a quantidade média em estoque (com 2 casas decimais) e o total de livros em estoque em uma mesma linha.  



// Neste exercício, você vai ler e escrever arquivos textos.  



// Escreva um programa usando as funções descritas acima. Crie funções auxiliares para organizar sua solução. 
// Não se esqueça de liberar a memória alocada dinamicamente quando não for mais necessária. Os nomes dos arquivos de entrada e saída 
// devem ser escolhidos livremente.  



// Assuma que nenhum título excede 127 caracteres. Não use acentuação. Assuma também que não há erro de formato no arquivo de entrada. 
// Se ocorrer erro na abertura de arquivos, o programa deve exibir uma mensagem informativa e ser abortado. 


//#include <stdio.h>
//#include <stdlib.h>
//
//void imprimir_erro(FILE * arquvio) {
//
//    if (arquvio == NULL) {
//
//        printf("Deu merda na abertura do arquivo!");
//
//        exit(1);
//    }
//}
//
//
//void exibe_infos(FILE* arqSaidaNome, FILE* arqSaidaEstoque) {
//
//
//    char buff_nome[81];
//    int buff_estoque;
//
//
//    float media = 0;
//    int soma = 0;
//    while (!feof(arqSaidaNome) && !feof(arqSaidaEstoque)) {
//        fscanf(arqSaidaNome, "%[^\n]\n", buff_nome);    // para que serve esse segundo \n nessa linha?
//        printf("O nome do Livro eh: %s\n", buff_nome);
//
//        
//
//        for (int i = 0;i < 5; i++) {
//            if (fscanf(arqSaidaEstoque, " %d", &buff_estoque) == 1) {
//
//                soma += buff_estoque;
//
//            }
//        }
//
//        media = (float)soma / 5;
//
//        printf("A media eh: %.2f\n", media);
//
//        printf("O total de livros no estoque eh: %d\n", soma);
//
//        printf("\n");
//
//        media = 0;
//        soma = 0;
//        
//
//    }
//
//
//}
//
//int main(void) {
//
//    FILE* arqEntrada;
//    FILE* arqSaidaNome;
//    FILE* arqSaidaEstoque;
//
//    arqEntrada = fopen("ExcEditora.txt", "r");
//    arqSaidaNome = fopen("NomesLivros.txt", "w");
//    arqSaidaEstoque = fopen("EstoqueLivros.txt", "w");
//    imprimir_erro(arqEntrada);
//    imprimir_erro(arqSaidaNome);
//    imprimir_erro(arqSaidaEstoque);
//
//
//    char buffer_nome[128], buffer_estoque[81];
//
//    while (fscanf(arqEntrada, " %[^/]/ %[^\n]\n", buffer_nome, buffer_estoque) == 2) {
//
//        fprintf(arqSaidaNome, "%s\n", buffer_nome);
//        fprintf(arqSaidaEstoque, "%s\n", buffer_estoque);
//    }
//
//    fclose(arqEntrada);
//    fclose(arqSaidaNome);
//    fclose(arqSaidaEstoque);
//
//    arqSaidaNome = fopen("NomesLivros.txt", "r");
//    arqSaidaEstoque = fopen("EstoqueLivros.txt", "r");
//    imprimir_erro(arqSaidaNome);
//    imprimir_erro(arqSaidaEstoque);
//
//    exibe_infos(arqSaidaNome, arqSaidaEstoque);
//
//    free(buffer_estoque);
//    free(buffer_nome);
//
//
//
//
//    return 0;
//}

//============================================================================================================================================
//#include <stdio.h>		TESTE TESTE TESTE
//#include <string.h>
//
//
//
//int main(void){
//    
//    char stringExistente[81];
//    char strAdicionada[] = "efg";
//    
//    FILE * arqEntrada = fopen("abcd.txt", "r");
//    
//    fscanf(arqEntrada," %[^\n]",stringExistente);
//    
//    fclose(arqEntrada);
//    
//    FILE * arqEntrada2 = fopen("abcd.txt","w");
//    
//    
//    strcat(stringExistente,strAdicionada);
//    
//    fprintf(arqEntrada2,"%s",stringExistente);
//    
//    fclose(arqEntrada2);
//    
//    return 0;
//}

//===================================================================================================================================================

// INCOMPLETO INCOMPLETO

//Prox Exc. Crie um arquivo texto com títulos de livros, seguido de barra (/), seguido do nome do autor ou autores separados 
//por ponto e vírgula(;), como mostra o exemplo abaixo :
// 
// Dom Casmurro / Machado de Assis
// O Nome da Rosa / Umberto Eco
// Angustia / Graciliano Ramos
// A Menina Que Roubava Livros / Karkus Zusak
// O Corpo Fala / Pierre Weil;Roland Tompakow
// Viagem ao Mundo dos Taleban / Louriva Santana
// Quem Mexeu no Meu Queijo ? / Spencer Johnson
// 
// 
//Nesta tarefa, você vai ler e escrever arquivos textos.
//Escreva um programa para ler seu arquivo e gerar um outro arquivo texto com título e autor(es) agrupado por letra
//inicial do título.A ordem dos títulos em cada grupo deve ser a mesma em que aparecem no arquivo de entrada.
//Mas os grupos devem ser exibidos em ordem alfabética.Caso não existam livros para uma determinada letra, nada
//será exibido.Cada título exibido deve ter o seguinte formato :
// 
//titulo.Autor : nome do autor ou
//titulo.Autores : lista de nome dos autores, separados por ponto e vírgula(;)
//Para o arquivo de entrada mostrado acima, o arquivo de saída gerado deve ter o seguinte formato e conteúdo :
//Titulos iniciados com A :
//Angustia.Autor : Graciliano Ramos
//A Menina Que Roubava Livros.Autor : Karkus Zusak
//Titulos iniciados com D :
//Dom Casmurro.Autor : Machado de Assis
//Titulos iniciados com O :
//O Nome da Rosa.Autor : Umberto Eco
//O Corpo Fala.Autores : Pierre Weil;Roland Tompakow
//Titulos iniciados com Q :
//Quem Mexeu no Meu Queijo ? .Autor : Spencer Johnson
//Titulos iniciados com V :
//Viagem ao Mundo dos Taleban.Autor : Louriva Santana
// 
// 
//Na sua implementação, crie, obrigatoriamente, um vetor de cadeias de caracteres para cada título de livro e outro
//para cada autor(es).Em ambos os vetores use o espaço de memória estritamente necessário para seu
//armazenamento.Crie funções auxiliares para organizar sua solução.Não se esqueça de liberar a memória alocada
//dinamicamente quando não for mais necessária.
//Assuma que o número máximo de livros no arquivo é 100 e que nenhum título e nem lista de autores excede 127
//caracteres.Não use acentuação.Considere apenas títulos começando com letras.Assuma também que não há erro
//de formato no arquivo de entrada.Se ocorrer erro na abertura de arquivos ou na alocação de memória, o programa
//deve exibir uma mensagem informativa e ser abortado.
//Dica 1: para leitura dos nomes com espaços, use o formato% [...].
//Dica 2 : para determinar se a leitura foi bem sucedida pode - se usar o valor de retorno da função fscanf.



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_LIVROS 100
//
//
//
//
//void organizaEmGrupos(char** vetorTitulos, int tamVetor);
//int tamanho_vetor(FILE* arquivo);
//
//
//int main(void) {
//
//    FILE* arqEntrada = fopen("C:/Users/pedro/OneDrive/PUC-RIO/Período2/Prog em C/TesteVsCode/ExcLivrosAfalbetico.txt", "r");
//    if (arqEntrada == NULL) {
//        printf("Erro na abertura do arquivo\n");
//        exit(-1);
//    }
//
//    int tamanho = tamanho_vetor(arqEntrada);
//    char titulo[128];
//    char autor[128];
//    char** vetorTitulos;
//
//
//    vetorTitulos = (char**)malloc(tamanho_vetor(arqEntrada) * sizeof(char*));
//    int i = 0;
//    while(i<MAX_LIVROS && fscanf(arqEntrada," %[^/]/ %[^\n]",titulo, autor) == 2){
//
//        vetorTitulos[i] = (char *)malloc ((strlen(titulo) + 1)*sizeof(char));
//        //vetorAutores[i] = (char *)malloc ((strlen(autor) + 1)*sizeof(char));
//
//        strcpy(vetorTitulos[i], titulo);
//        //strcpy(vetorAutores[i], autor);
//
//
//        i++;
//    }
//    organizaEmGrupos(vetorTitulos, tamanho);
//    fclose(arqEntrada);
//    return 0;
//}
//
//
//int tamanho_vetor(FILE* arquivo) {
//    int cont = 0;
//    char buffer[256];  // Usado para ler as linhas do arquivo
//
//    // Ler até o final do arquivo
//    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {//refazer com fscanf
//        cont++;
//    }
//
//    // Resetar o ponteiro do arquivo para o início
//    rewind(arquivo);
//
//    return cont;
//}
//
//
//
//void organizaEmGrupos(char** vetorTitulos, int tamVetor) {
//
//    char letra;
//    int i;
//
//    for (int i = 65; i <= 90; i++) {
//        printf("%c:\n", i);
//        for (int j = 0; j < tamVetor; j++) {
//            if (vetorTitulos[j][0] == i) {
//                printf("    %s\n", vetorTitulos[j]);
//            }
//        }
//
//    }
//
//}

//===================================================================================================================================================
