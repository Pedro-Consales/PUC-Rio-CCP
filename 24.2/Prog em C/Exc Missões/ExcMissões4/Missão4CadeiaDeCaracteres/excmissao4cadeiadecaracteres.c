//1. Escreva a função contaLetras(usando obrigatoriamente aritmética de ponteiros) que: -recebe uma cadeia(ou seja, um ponteiro para uma cadeia), e o endereço de duas variáveis onde devem devolvidas
//as respostas - devolve nas variáveis cujos endereço foram recebidos dois valores : o número de maiúsculas e o número de
//minúsculas.
//Implemente um programa que teste essa função.

//#include <stdio.h>
//#include <ctype.h>
//
//void contaletras(char* string, int* nMaisuculas, int* nMinusculas) {
//
//    int i;
//    int contMaiusculas;
//    int contMinusculas;
//
//    contMaiusculas = 0;
//    contMinusculas = 0;
//    i = 0;
//    while (string[i] != '\0') {
//
//        if (isupper(string[i])) {
//
//
//            contMaiusculas++;
//
//        }
//        else if (islower(string[i])) {
//
//            contMinusculas++;
//
//        }
//
//        i++;
//
//    }
//    *nMaisuculas = contMaiusculas;
//    *nMinusculas = contMinusculas;
//}
//
//
//int main(void) {
//
//    char* nome = "Pedro Consales Margaronis";
//    int qtdMaiusculas;
//    int qtdMinusculas;
//
//    contaletras(nome, &qtdMaiusculas, &qtdMinusculas);
//
//
//    printf("A quatidade de letras MAIUSCULAS na string eh: %d", qtdMaiusculas);
//
//    printf("\nA quatidade de letras MINUSCULAS na string eh: %d", qtdMinusculas);
//
//
//    return 0;
//}

//=======================================================================================================================================================


// Implemente uma função que receba uma cadeia de caracteres (string) como parâmetro e altere nessa string as 
// ocorrências de caracteres maiúsculos para minúsculos. Essa função deve obedecer ao protótipo:           
// void minusculo (char* str); 
// Implemente também um programa que teste essa função.

//#include <stdio.h>
//#include <ctype.h>
//
//void minusculo(char* str) {
//
//    int i;
//    i = 0;
//    while (str[i] != '\0') {
//
//        if (isupper(str[i]));
//
//        str[i] = tolower(str[i]);
//
//        i++;
//    }
//}
//
//
//
//int main(void) {
//
//    char string[] = "MuDaR MaIoR PaRa MeNoR";
//
//    minusculo(string);
//
//    printf("%s", string);
//
//    return 0;
//}

//======================================================================================================================================================

// Escreva, em C, a função ultimoNome que recebe uma cadeia com um nome completo de uma pessoa e retorna o seu 
// sobrenome (isto é, o seu último nome). Considere que há apenas um único espaço em branco entre nomes e que após o 
// último nome não há espaços em branco. Não crie novas cadeias (estáticas ou dinâmicas). 

// Exemplos:  
// com “STEVEN PAUL JOBS”, a função retorna “JOBS”  
// com “SILVA”, a função retorna “SILVA”  
// com “”, a função retorna “” 
// Implemente um programa que teste essa função. 


//
//
//#include <stdio.h>
//#include <string.h>
//
//char* ultimoNome(char* strNome) {
//
//    int i;
//    int tamStr;
//    char* ultimo = strNome;//PQ PRECISA SER UM PONTEIRO??
//    tamStr = strlen(strNome);
//
//    for (i = 0;i < tamStr;i++) {
//
//        if (strNome[i] == ' ') {
//
//            ultimo = &strNome[i + 1];// PQ PRECSIA SER UM ENDEREÇO, E PQ i+1??
//
//        }
//    }
//
//    return ultimo;
//}
//
//
//int main(void) {
//
//    char* nome = "Pedro Consales";
//
//    printf("%s", ultimoNome(nome));
//
//
//    return 0;
//}

//=======================================================================================================================================================

// Escreva a função criaNome que gera automaticamente e retorna o nome completo de um bebê, a partir do primeiro 
// nome dado ao bebê, do nome completo de solteira da mãe e do nome completo do pai. O nome do bebê é composto 
// pelo seu primeiro nome + último nome da mãe + último nome do pai, separados por espaços. 
// Função criaNome: - recebe uma cadeia com o primeiro nome do bebê, uma cadeia com o nome completo da mãe e uma cadeia com o 
// nome completo do pai; - cria e retorna uma nova cadeia contendo o nome completo do bebê, gerado de acordo com o critério descrito. 
// Utilizar alocação dinâmica de memória do tamanho exato necessário. Retorna NULL quando não for possível alocar 
// dinamicamente. Essa função deve usar, adequadamente, a função ultimoNome, mesmo que você não a tenha feito.  
// Exemplo: a seguinte chamada da função com os argumentos: 
// criaNome("Pedro", "Ana Luiza Resende", "Rui Alberto Medeiros") 
// retornaria (um ponteiro para) uma nova cadeia contendo o nome "Pedro Resende Medeiros" 
// Implemente um programa que teste essa função.

#include <stdio.h>

// char *criaNomeCompletoBebe(char *primNomeBB, char *nomeCompletoMAE, char *nomeCompletoPAI){






// }

int main(void) {

    char primerioNomeBB[100];
    char nomeCompletoMae[100];
    char nomeCompletoPai[100];

    printf("Digite o nome completo da MAE: ");
    scanf("%[^\n]", nomeCompletoMae);

    printf("Digite o nome completo do PAI: ");
    scanf("%[^\n]", nomeCompletoPai);

    printf("Digite o primeiro nome do FILHO: ");
    scanf("%[^\n]", primerioNomeBB);


    printf("\nO nome completo da mae eh: %s", nomeCompletoMae);

    printf("\nO nome completo do pai eh: %s", nomeCompletoPai);

    printf("\nO primeiro nome do bebe eh: %s", primerioNomeBB);


    return 0;


}