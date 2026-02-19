
/*

LAB 3 INF1010 EDA 2025-2

Nome: Gabriel de Castro Fontes
Matricula: 2421177

Nome: Pedro Consales
Matricula: 2410238

*/

#include <stdio.h>
#include <stdlib.h>


typedef struct bitvector BitVector;
struct bitvector {
    int max; // número máximo de elementos do conjunto
    int* vector; // vetor de inteiros que representa o conjunto
};


void print_bits(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        unsigned int bit = (n >> i) & 1u;
        printf("%u", bit);
        if (i % 8 == 0) printf(" "); // separa em blocos de 8 bits
    }
}

void print_bitvector(BitVector* s) {
    int qtd_inteiros = (s->max + 31) / 32;
    printf("\nBitVector (%d bits):\n", s->max);

    for (int i = 0; i < qtd_inteiros; i++) {
        printf("vector[%d] = ", i);
        print_bits((unsigned int)s->vector[i]);
        printf(" (0x%08X)\n", s->vector[i]);
    }
    printf("\n");
}


BitVector* setremove(BitVector * s, int i) {
    // Implemente aqui a função set_remove
    int index_do_elemnto = i/(sizeof(int)*8);
    // nessa linha faço o i(vamos dizer que é 30) 30/4*8 -> 30/32 = (32 cabe 0 vezes em 30 ou seja, é 0 e resta 30)
    // isso é igual a 0

    int index_do_bit = i%(sizeof(int)*8);
    // o resto é isso aqui então isso é = 30

    unsigned int num = s->vector[index_do_elemnto];
    // num vai ser igial ao slemento s->vector[0]

    unsigned int buff_num = num; //crio um buffer para não perder o original

    int desolc = (1u << index_do_bit); //“Aqui eu pego o número 1u (binário 000...0001) e desloco 30 bits para a esquerda, fazendo com que apenas o bit 30 fique em 1.”
    // original 0000 0000 | 0000 0000 | 0000 0000 | 0000 0001
    // pós shift 0100 0000 0000 0000 0000 0000 0000 0000
    desolc = ~(desolc);
    // aqui eu pego o pós shift e inverto os bits
    // 1011 1111 1111 1111 1111 1111 1111 1111

    buff_num &= desolc;
    //faço um & lógico para apagar o bit que tiver diferente
    // original buffnul = 0xF3AC9CFA
    // 1111 0011 1010 1100 1001 1100 1111 1010
    //  &
    // desloc 
    // 1101 1111 1111 1111 1111 1111 1111 1111
    // result
    // 1101 0011 1010 1100 1001 1100 1111 1010
    // veja que o bit 30 mudou!

    s->vector[index_do_elemnto] = buff_num;

    return s;
}

BitVector* set_diferenca(BitVector* r, BitVector* s) {
    int qtd_inteiros = (r->max + 31) / 32;

    BitVector* t = (BitVector*)malloc(sizeof(BitVector));
    t->max = r->max;
    t->vector = (int*)malloc(qtd_inteiros * sizeof(int));

    for (int i = 0; i < qtd_inteiros; i++) {
        t->vector[i] = r->vector[i] & ~(s->vector[i]);
    }

    return t;
}

int main(void)
{
    BitVector* s = (BitVector*)malloc(sizeof(BitVector));
    s->max = 80;

    int qtd_inteiros = (s->max + 31) / 32;
    //Divde a quatidade total de bits por 32 (inteiro) e obtem a qunatidade de inteiros

    // O +31 garante o arredondamento para cima na divisão inteira.
    // Ele serve para que, se houver qualquer sobra de bits após
    // dividir em blocos de 32 bits, a gente conte mais um bloco completo.
    //
    // Isso acontece porque o maior resto possível em uma divisão por 32 é 31.
    // Então, somar 31 empurra qualquer resto não nulo para o próximo inteiro.
    //
    // -------------------------------------------------------------
    // Visualizando quantos bits cabem em cada exemplo:
    //
    // Exemplo 1: max = 63 bits
    //   63 / 32 = 1 bloco completo (32 bits) e SOBRAM 31 bits fora.
    //   Precisa de mais um bloco para guardar esses 31 bits.
    //   (63 + 31) / 32 = 94 / 32 = 2 blocos 
    //
    //     [ Bloco 0: 32 bits ] [ Bloco 1: 31 bits ]
    //      total = 63 bits armazenados corretamente
    //
    // [■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■] (32 bits)
    // [■■■■■■■■■■■■■■■■■■■■■■■■■■■■■-] (31 bits sobram fora!)
    // ↓
    // (63 + 31) / 32 = 94 / 32 = 2 → preciso de 2 blocos
    // 31 é o resto
    //
    // -------------------------------------------------------------

    s->vector = (int*)malloc(qtd_inteiros * sizeof(int));
    s->vector[0] = 0x000000FA;
    s->vector[1] = 0x11FFAABB;
    s->vector[2] = 0xCCDDEEFF;

    printf("ANTES:\n");
    print_bitvector(s);

    // Remover bits 30, 39 e 73
    setremove(s, 30);
    setremove(s, 39);
    setremove(s, 73);

    printf("DEPOIS:\n");
    print_bitvector(s);


    BitVector* r = (BitVector*)malloc(sizeof(BitVector));
    r->max = 80;
    r->vector = (int*)malloc(qtd_inteiros * sizeof(int));

    // R do enunciado
    r->vector[0] = 0x05EE00F1;
    r->vector[1] = 0x00114455;
    r->vector[2] = 0x00003377;

    printf("\nConjunto R:\n");
    print_bitvector(r);

    printf("\nConjunto S (após remoções):\n");
    print_bitvector(s);

    BitVector* t = set_diferenca(r, s);

    printf("\nT = R - S:\n");
    print_bitvector(t);

    free(r->vector);
    free(r);
    free(t->vector);
    free(t);
    free(s->vector);
    free(s);

    return 0;
}