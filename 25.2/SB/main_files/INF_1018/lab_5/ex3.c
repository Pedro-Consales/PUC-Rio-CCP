#include <stdio.h>

struct X1 {
  char c1;
  int i;
  char c2;
};

struct X2 {
  long l;
  char c;
};

struct X3 {
  int i;
  char c1;
  char c2;
};

struct X4 {
  struct X2 x;
  char c;
};


struct X5 {
  char c1;
  char c2;
  char c3;
};


struct X6 {
  short s1;   // offset 0-1 (2 bytes)
  //padding   // offset 2-3 (2 bytes) ← padding para alinhar o int
  int i;      // offset 4-7 (4 bytes) ← precisa estar em múltiplo de 4!
  char c[3];  // offset 8-10 (3 bytes)
  //padding   // offset 11 (1 byte) ← padding para alinhar s2
  short s2;   // offset 12-13 (2 bytes) ← precisa estar em múltiplo de 2!
  //padding   // offset 14-15 (2 bytes) ← padding final da struct!
};
// Tamanho total: 16 bytes

union U1 {
  int i;
  char c[5];
};
// 16 17 18 19 20 21 22 23 (até 23 pois o tamanho tem que ser multiplo do maior alinhamento)
// i  i  i  i  (alinhamento 4)
// ou
// c  c  c  c  c  (alinhamento 1)



union U2 {
  short s;
  char c[5];
};

// 2 + 5 = 7
// 16 17 18 19 20 21 22 23
// s  s
// ou
// c. c. c. c. c. pp pp pp
void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - Hex: %02x / Dec: %d\n", p1, *p1, *p1);
    p1++;
  }
}

int main(void)
{
    struct X1 a = {0xa1, 0xb1b2b3b4, 0xc1};
    printf("Tamanho da struct X1: %zu\n", sizeof(a));

    dump(&a, sizeof(a));
    printf("\n\n");

    struct X2 b = {0xb1b2b3b4b5b6b7b8, 0xc1};

    printf("Tamanho da struct X2: %zu\n", sizeof(b));

    dump(&b, sizeof(b));

    printf("\n\n");

    struct X3 c = {0xb1b2b3b4, 0xc1, 0xd1};

    printf("Tamanho da struct X3: %zu\n", sizeof(c));

    dump(&c, sizeof(c));

    printf("\n\n");

    struct X4 d = {{0xb1b2b3b4b5b6b7b8, 0xc1}, 0xd1};

    printf("Tamanho da struct X4: %zu\n", sizeof(d));

    dump(&d, sizeof(d));

    printf("Percebe-se que o maior alinhamento depois do padding tem que ser multipo do maior alinhamento se para na casa 17 o próximo numero multiplo de 8 (que é o o sizeof long de dentro da sturct) é 24\n\n");

    struct X5 e = {0xb1, 0xc1, 0xd1};

    printf("Tamanho da struct X5: %zu\n", sizeof(c));

    dump(&e, sizeof(e));

    printf("\n\n");

    struct X6 f = {0xa1a2, 0xb1b2b3b4, {0xc1, 0xc2, 0xc3}, 0xd1d2};

    printf("Tamanho da struct X6: %zu\n", sizeof(f));

    dump(&f, sizeof(f));

    printf("\n\n");


     union U1 u = {.i=0xa1a2a3a4};


    printf("Tamanho do union U1: %zu\n", sizeof(u));

    printf("Dump após inicialização com int 0xa1a2a3a4:\n");
    dump(&u, sizeof(u));

    printf("\n");

    // Agora inicializando com o array de chars
    union U1 u2 = {.c = {'A','B','C','D','E'}};

    printf("Tamanho do union U1: %zu\n", sizeof(u2));

    printf("Dump após inicialização com {'A','B','C','D','E'}:\n");
    dump(&u2, sizeof(u2));

    printf("\nInterpretando os 4 primeiros bytes de u2 como int: 0x%08x (%d)\n", u2.i, u2.i);

    return 0;
}
