//Arquivo para implementação das funções do programa

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

/* imprime 16 bytes em hexa do MSB→LSB (forma humana) */
static void dump_hex(const BigInt x) {
    for (int i = 15; i >= 0; --i) printf("%02X", x[i]);
    putchar('\n');
}

int main(void)
{
    BigInt a, b, r;

    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║     TESTES COMPLETOS - BIBLIOTECA BIGINT          ║\n");
    printf("╚════════════════════════════════════════════════════╝\n\n");

    // ========== TESTE 1 ==========
    printf("════════════════ TESTE 1: 5 e 3 ════════════════\n");
    big_val(a, 5);
    big_val(b, 3);
    printf("a (hex)              : "); dump_hex(a);
    printf("b (hex)              : "); dump_hex(b);
    
    big_sum(r, a, b);
    printf("a + b (hex)          : "); dump_hex(r);
    
    big_sub(r, a, b);
    printf("a - b (hex)          : "); dump_hex(r);
    
    big_mul(r, a, b);
    printf("a * b (hex)          : "); dump_hex(r);
    
    big_shl(r, a, 1);
    printf("a << 1 (hex)         : "); dump_hex(r);
    
    big_shr(r, a, 1);
    printf("a >> 1 (lógico)      : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 2 ==========
    printf("════════════════ TESTE 2: 10 e 20 ════════════════\n");
    big_val(a, 10);
    big_val(b, 20);
    printf("a (hex)              : "); dump_hex(a);
    printf("b (hex)              : "); dump_hex(b);
    
    big_sum(r, a, b);
    printf("a + b (hex)          : "); dump_hex(r);
    
    big_sub(r, a, b);
    printf("a - b (hex)          : "); dump_hex(r);
    
    big_mul(r, a, b);
    printf("a * b (hex)          : "); dump_hex(r);
    
    big_shl(r, a, 2);
    printf("a << 2 (hex)         : "); dump_hex(r);
    
    big_shr(r, b, 1);
    printf("b >> 1 (lógico)      : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 3 ==========
    printf("════════════════ TESTE 3: 255 e 1 ════════════════\n");
    big_val(a, 255);
    big_val(b, 1);
    printf("a (hex)              : "); dump_hex(a);
    printf("b (hex)              : "); dump_hex(b);
    
    big_sum(r, a, b);
    printf("a + b (hex)          : "); dump_hex(r);
    
    big_sub(r, a, b);
    printf("a - b (hex)          : "); dump_hex(r);
    
    big_mul(r, a, b);
    printf("a * b (hex)          : "); dump_hex(r);
    
    big_shl(r, a, 1);
    printf("a << 1 (hex)         : "); dump_hex(r);
    
    big_shr(r, a, 4);
    printf("a >> 4 (lógico)      : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 4 ==========
    printf("════════════════ TESTE 4: 100 e 200 ════════════════\n");
    big_val(a, 100);
    big_val(b, 200);
    printf("a (hex)              : "); dump_hex(a);
    printf("b (hex)              : "); dump_hex(b);
    
    big_sum(r, a, b);
    printf("a + b (hex)          : "); dump_hex(r);
    
    big_sub(r, b, a);
    printf("b - a (hex)          : "); dump_hex(r);
    
    big_mul(r, a, b);
    printf("a * b (hex)          : "); dump_hex(r);
    
    big_shl(r, a, 3);
    printf("a << 3 (hex)         : "); dump_hex(r);
    
    big_shr(r, b, 2);
    printf("b >> 2 (lógico)      : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 5 ==========
    printf("════════════════ TESTE 5: 1000 e 500 ════════════════\n");
    big_val(a, 1000);
    big_val(b, 500);
    printf("a (hex)              : "); dump_hex(a);
    printf("b (hex)              : "); dump_hex(b);
    
    big_sum(r, a, b);
    printf("a + b (hex)          : "); dump_hex(r);
    
    big_sub(r, a, b);
    printf("a - b (hex)          : "); dump_hex(r);
    
    big_mul(r, a, b);
    printf("a * b (hex)          : "); dump_hex(r);
    
    big_shl(r, a, 1);
    printf("a << 1 (hex)         : "); dump_hex(r);
    
    big_shr(r, a, 1);
    printf("a >> 1 (lógico)      : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 6 ==========
    printf("════════════════ TESTE 6: 256 e 256 ════════════════\n");
    big_val(a, 256);
    big_val(b, 256);
    printf("a (hex)              : "); dump_hex(a);
    printf("b (hex)              : "); dump_hex(b);
    
    big_sum(r, a, b);
    printf("a + b (hex)          : "); dump_hex(r);
    
    big_sub(r, a, b);
    printf("a - b (hex)          : "); dump_hex(r);
    
    big_mul(r, a, b);
    printf("a * b (hex)          : "); dump_hex(r);
    
    big_shl(r, a, 8);
    printf("a << 8 (hex)         : "); dump_hex(r);
    
    big_shr(r, a, 1);
    printf("a >> 1 (lógico)      : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 7 ==========
    printf("════════════════ TESTE 7: 65535 e 1 ════════════════\n");
    big_val(a, 65535);
    big_val(b, 1);
    printf("a (hex)              : "); dump_hex(a);
    printf("b (hex)              : "); dump_hex(b);
    
    big_sum(r, a, b);
    printf("a + b (hex)          : "); dump_hex(r);
    
    big_sub(r, a, b);
    printf("a - b (hex)          : "); dump_hex(r);
    
    big_mul(r, a, b);
    printf("a * b (hex)          : "); dump_hex(r);
    
    big_shl(r, a, 1);
    printf("a << 1 (hex)         : "); dump_hex(r);
    
    big_shr(r, a, 8);
    printf("a >> 8 (lógico)      : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 8 - NÚMEROS NEGATIVOS ==========
    printf("════════════════ TESTE 8: -10 e 5 (NEGATIVOS) ════════════════\n");
    big_val(a, -10);
    big_val(b, 5);
    printf("a (hex)              : "); dump_hex(a);
    printf("b (hex)              : "); dump_hex(b);
    
    big_sum(r, a, b);
    printf("a + b (hex)          : "); dump_hex(r);
    
    big_sub(r, a, b);
    printf("a - b (hex)          : "); dump_hex(r);
    
    big_shl(r, a, 1);
    printf("a << 1 (hex)         : "); dump_hex(r);
    
    big_shr(r, a, 1);
    printf("a >> 1 (lógico)      : "); dump_hex(r);
    
    big_sar(r, a, 1);
    printf("a >> 1 (aritmético)  : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 9 - SHIFT ARITMÉTICO ==========
    printf("════════════════ TESTE 9: -100 (SHIFT ARITMÉTICO) ════════════════\n");
    big_val(a, -100);
    printf("a (hex)              : "); dump_hex(a);
    
    big_sar(r, a, 1);
    printf("a >> 1 (aritmético)  : "); dump_hex(r);
    
    big_sar(r, a, 2);
    printf("a >> 2 (aritmético)  : "); dump_hex(r);
    
    big_sar(r, a, 4);
    printf("a >> 4 (aritmético)  : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 10 - COMPARAÇÃO LÓGICO vs ARITMÉTICO ==========
    printf("════════════════ TESTE 10: -8 (LÓGICO vs ARITMÉTICO) ════════════════\n");
    big_val(a, -8);
    printf("a (hex)              : "); dump_hex(a);
    
    big_shr(r, a, 1);
    printf("a >> 1 (lógico)      : "); dump_hex(r);
    
    big_sar(r, a, 1);
    printf("a >> 1 (aritmético)  : "); dump_hex(r);
    
    big_shr(r, a, 2);
    printf("a >> 2 (lógico)      : "); dump_hex(r);
    
    big_sar(r, a, 2);
    printf("a >> 2 (aritmético)  : "); dump_hex(r);
    printf("\n");

    // ========== TESTE 11 - COMPLEMENTO DE 2 ==========
    printf("════════════════ TESTE 11: COMPLEMENTO DE 2 ════════════════\n");
    big_val(a, 5);
    printf("a (hex)              : "); dump_hex(a);
    
    big_comp2(r, a);
    printf("-a (comp2) (hex)     : "); dump_hex(r);
    
    big_sum(b, a, r);
    printf("a + (-a) (hex)       : "); dump_hex(b);
    printf("\n");

    // ========== TESTE 12 - SHIFTS GRANDES ==========
    printf("════════════════ TESTE 12: SHIFTS GRANDES ════════════════\n");
    big_val(a, 12345);
    printf("a (hex)              : "); dump_hex(a);
    
    big_shl(r, a, 16);
    printf("a << 16 (hex)        : "); dump_hex(r);
    
    big_shr(r, a, 8);
    printf("a >> 8 (lógico)      : "); dump_hex(r);
    
    big_val(a, -1000);
    printf("\na = -1000 (hex)      : "); dump_hex(a);
    
    big_sar(r, a, 10);
    printf("a >> 10 (aritmético) : "); dump_hex(r);
    printf("\n");

    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║            TESTES CONCLUÍDOS COM SUCESSO!         ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");

    return 0;
}