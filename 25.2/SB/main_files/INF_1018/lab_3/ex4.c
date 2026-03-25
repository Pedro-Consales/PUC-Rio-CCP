#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n)
{
    unsigned char x_buf = x;
    for(int i = 0; i < n; i++)
    {
        unsigned char mlb = x_buf & 0x80;
        
        mlb >>= 7;

        x_buf <<= 1;

        x_buf = x_buf | mlb;
    }

    return x_buf;
}


//x_buf é um buffer para eu não mexer no valor de x

//o for serve para eu mover o shift quantas vezes eu indicar no n
//ah mas por que você não usa 'n' no shift
//pois se eu fizer de uma vez eu vou perder o primeiro que é para adicionar no início

//então:

//primeira interação
//mls (most left bit) = 
// 0110 0001
// &
// 1000 0000
//-----------
// 0000 0000
// mlb >>=7 pois o bit mais a direita fica como zero, nesse caso não muda nada, mas no próximo vai ficar mais claro
//
// x_buf <<= 1 -> 1100 0010
//                |
//                0000 0000
//                -----------
//                1100 0010 



//segunda interação
// mls (most left bit) =
// 1100 0010
// &
// 1000 0000
//-----------
// 1000 0000 Vemos que de fato nesse caso é um. Mas eu não posso simplesmente juntar, eu tenho que:
// mlb >>= 7 -> 000 0001
// Agora com isso eu posso juntar
// x_buf <<= 1 -> 1000 0100
//                |
//                0000 0001
//                -----------
//                1000 0101
// e por ai vai determinado a quantidade de vezes que eu escolher o n. 




int main(void)
{
    unsigned char x = 97;
    unsigned char val;

    val = rotate_left(x, 1);

    printf("Shift 1\n");
    printf("Valor antes:  %08b\n", x);
    printf("Valor depois: %08b\n\n", val);

    val = rotate_left(x, 2);

    printf("Shift 2\n");
    printf("Valor antes:  %08b\n", x);
    printf("Valor depois: %08b\n\n", val);

    val = rotate_left(x, 7);

    printf("Shift 7\n");
    printf("Valor antes:  %08b\n", x);
    printf("Valor depois: %08b\n\n", val);

}