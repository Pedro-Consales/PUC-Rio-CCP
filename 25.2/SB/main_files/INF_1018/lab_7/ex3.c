#include <stdio.h>


int main(void)
{

    int i, num;
    i = 0;
    num = 1;
    while (i < 10)
    {
        int quadrado;

        quadrado = num*num;
        printf("%d", quadrado);
        printf("\n");
        printf("\n");
        num++;
        i++;
    }
    

    return 0;
}

//Pensei em fazer calculando i*i, e rodando o while até 11, ou, quando fosse caluclar o quadrado, faria i+1.
//Mas acho que essa forma é a mais adequada, porém menos eficiente.