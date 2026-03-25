#include <stdio.h>

void dump(void *p, int n) {
    unsigned char *p1 = p;
    while (n--) {
        printf("%p - %02x\n", p1, *p1);
        p1++;
    }
}

int main(void) {
    signed char sc = -1;
    unsigned int ui = sc;

    printf("sc = %d\n", sc);
    printf("ui (%%u) = %u\n", ui);
    printf("ui (%%x) = %x\n", ui);

    printf("\nDump de ui:\n");
    dump(&ui, sizeof(ui));

    return 0;
}


// Passo 1: sc = -1 em signed char (8 bits) → 11111111
// Passo 2: promoção para int (32 bits signed) → 11111111 11111111 11111111 11111111 (-1)
// Passo 3: conversão para unsigned int (32 bits) → 4294967295
