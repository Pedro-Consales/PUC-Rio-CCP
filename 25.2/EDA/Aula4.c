//Exemplo de ponteiro para função (void dentro do parâmetro da função)
#include <stdio.h>

void dump(void *p, int n)
{
    unsigned char* p1 = p;//"Converto para char* porque char sempre ocupa 1 byte, assim posso percorrer a memória byte a byte".
    
    int contBytes = 0;
    while(contBytes < n)
    {
        printf("%p --> hex: %02X / dec: %d\n", p1, *p1, *p1);
        *(p1++);
        contBytes++;
    }
}

int main(void)
{
    
    int i = 10000;
    dump(&i,sizeof(i));

    return 0;
}

//O parâmetro é void* para que a função aceite qualquer tipo de variável. Dentro dela, converto para char* porque char tem 1 byte e permite acessar a memória byte a byte

// entrada -> float i = 12.0

// 0x16d132ca8 --> 0
// 0x16d132ca9 --> 0
// 0x16d132caa --> 64
// 0x16d132cab --> 65

// O que está acotnecendo no output, é 

//“Imprimindo o endereço do byte em hexadecimal na RAM → Pegando o conteúdo do byte em hexadecimal e por ser %d é transformando para decimal.”
// ==
//À esquerda, %p mostra o endereço do byte (formato de ponteiro, normalmente em hex). --> À direita, %d mostra o conteúdo numérico daquele byte em decimal. O mesmo conteúdo pode ser exibido em hex com %02X.”


//0x64 → 6*16ˆ1 + 4*16ˆ0 = 6*16+4 = 96+4 = 100