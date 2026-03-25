#include <stdio.h>

unsigned char switch_byte(unsigned char x)
{
    unsigned char firstHalf = x & 0xF0;
    unsigned char secondHalf = x & 0x0F;

    firstHalf >>= 4;
    secondHalf <<= 4;
    
    return firstHalf | secondHalf;
}

//Eu obtenho a primeira parte com apagando os bits da segunda parte com uma mascara
// Primeira metade:
// 1010 0111
// &
// 1111 0000
//-------------
// 1010 0000

//Agora para a segunda metade eu faço o oposto com a máscara oposta
// 1010 0111
// &
// 0000 1111
//-------------
// 0000 0111

//Agora como eu inverto?
//Basta eu dar um shift de 4 bits que é meio byte.

//Para o primeiro 1010 0000 x >>=4
// 0000 1010

//para o segundo 0000 0111 x <<= 4
// 0111 0000

//E no final faço uma ultima operação com o | para juntas aos dois
// 0000 1010
// |
// 0111 0000
//-------------
// 0111 1010


int main(void)
{
    unsigned char x = 167;
    
    unsigned char var = switch_byte(x);


    printf("Caractere: %c --> ASCII: %d --> Bin: %08b --> Hex: %0X  \n\n", x, x, x, x);

    printf("Inversão de byte!\n\n");

    printf("Caractere: %c --> ASCII: %d --> Bin: %08b --> Hex: %0X  \n\n", var, var, var, var);

}