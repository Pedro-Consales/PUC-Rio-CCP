#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* retornaStrReduzida(char *str, int n);


int main(void)
{

    char str[] = "Luciana";

    int n = 4;

    char* novaStr = retornaStrReduzida(str, n);

    printf("%s\n\n", str);

    printf("%s", novaStr);

    return 0;
}


char* retornaStrReduzida(char* str, int n)
{
    //Luciana
    int tamanhoStr = strlen(str);

    int tamanhoNovaStr = tamanhoStr - n;

    char* novaStr = (char*)malloc((tamanhoNovaStr+1)*sizeof(char));
    
    if(novaStr == NULL)
    {
        printf("Erro ao alocar memoria na funcao");

        return 0;
    }


    int i;
    for(i = 0; i < tamanhoNovaStr; i++)
    {

        novaStr[i] = str[i];

    }

    novaStr[i]= '\0';
    
    return novaStr;
}
