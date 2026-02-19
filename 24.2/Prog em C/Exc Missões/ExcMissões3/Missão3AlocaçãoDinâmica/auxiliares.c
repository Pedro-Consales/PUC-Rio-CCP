//#include "auxiliares.h"
//#include <stdlib.h>
//
//int* criaVetorDeProdutosZerados(int* vetorCod, int* vetorQtdEstoque, int nProdutos, int* ptr) {
//    int contProdEstoqueZerados;
//    int cont;
//    int i;
//
//    contProdEstoqueZerados = 0;
//    for (i = 0; i < nProdutos;i++) {
//
//        if (vetorQtdEstoque[i] == 0) {
//
//            contProdEstoqueZerados++;
//
//        }
//    }
//
//    *ptr = contProdEstoqueZerados;
//
//
//    int* vetorDevolvido = (int*)malloc(contProdEstoqueZerados * sizeof(int));
//    cont = 0;
//    for (i = 0;i < nProdutos;i++) {
//        if (vetorQtdEstoque[i] == 0) {
//
//            vetorDevolvido[cont] = vetorCod[i];
//            cont++;
//        }
//    }
//
//
//
//    return vetorDevolvido;
//}
