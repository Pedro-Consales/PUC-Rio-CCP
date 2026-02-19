// Escreva a função criaVetorDeProdutosZerados, que:
//     - recebe um vetor de inteiros com os códigos dos produtos vendidos em uma loja, um vetor de inteiros com a quantidade em estoque de cada 
//      produto (onde estoque[i] corresponde a codigo[i]) e o número de produtos. A função também recebe o endereço de uma variável onde deve ser 
//      devolvido o número de produtos com estoque zerado;
//     - retorna um novo vetor (ou seja, o endereço do primeiro elemento de um novo vetor) de inteiros, criado com o tamanho exato necessário, 
//     apenas com os códigos dos produtos com estoque igual a 0. A função deve também devolver, numa variável cujo endereço foi recebido como 
//     parâmetro, 
//     o número de produtos com estoque zerado.
// Implemente um programa modularizado que teste essa função.
// Escreva um programa para testar sua função.

//Questões COM MÓDULO!!!!!!!!!!










//=====


//#include "auxiliares.h"
//
//int main(void) {
//
//    int i;
//    int CodProduto[6] = { 123,456,789,987,654,321 };
//    int QtdEstoque[6] = { 10,20,0,30,0,0 };
//    int qtdEstoqueZerado;
//    int* vetorResultado;
//
//    vetorResultado = criaVetorDeProdutosZerados(CodProduto, QtdEstoque, 6, &qtdEstoqueZerado);
//
//    for (i = 0;i < qtdEstoqueZerado;i++) {
//
//        printf("Os codigos seguintes obtiveram estoque 0: %d \n", vetorResultado[i]);
//
//    }
//
//    printf("\nNo total foram %d produtos com o estoque zerado", qtdEstoqueZerado);
//
//
//    return 0;
//}

//======================================================================================================================================================


// Implemente uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as suas respectivas quantidades de elementos, 
// n1 e n2. A função deve retornar um terceiro vetor v3, com capacidade para (n1 + n2) elementos, alocado dinamicamente, 
// contendo os elementos de v1 e v2 de modo intercalado. Por exemplo, se v1 = {1, 3, 5, 7} e v2 = {2, 4, 6, 8, 10, 12}, v3 irá conter {1, 2, 3, 4, 5, 6, 7, 8, 10, 12}. 
// Observe que dependendo do número de elementos, os últimos valores podem não ficar intercalados.
// Escreva um programa para testar sua função.
//
//#include <stdio.h>
//#include <stdlib.h>
//#define qtdElementosV1 4
//#define qtdElementosV2 6
//
//int teste(int* v1, int* v2, int qtdEleV1, int qtdEleV2) {
//
//    int* v3 = (int*)malloc((qtdEleV1 + qtdEleV2) * sizeof(int));
//
//    int i = 0, j = 0, k = 0;
//
//    // Intercala os elementos de v1 e v2
//    while (i < qtdEleV1 && j < qtdEleV2) {
//        v3[k++] = v1[i++];
//        v3[k++] = v2[j++];
//    }
//
//    while (i < qtdEleV1) {
//        v3[k++] = v1[i++];
//    }
//
//    // Adiciona os elementos restantes de v2, se houver
//    while (j < qtdEleV2) {
//        v3[k++] = v2[j++];
//    }
//
//    return v3;
//}
//
//
//
//
//
//int main(void) {
//
//    int v1[qtdElementosV1] = { 1, 3, 5, 7 };
//    int v2[qtdElementosV2] = { 2, 4, 6, 8, 10, 12 };
//    int* result;
//
//    result = teste(v1, v2, qtdElementosV1, qtdElementosV2);
//
//    for (int i = 0; i < qtdElementosV1 + qtdElementosV2;i++) {
//
//        printf("%d", result[i]);
//
//    }
//
//    return 0;
//}


//======================================================================================================================================================

