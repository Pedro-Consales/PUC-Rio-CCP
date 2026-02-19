#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Enunciado:
// Implemente uma função que recebe como parametros uma cadeia de caracteres e um caracetere
// c, e retorne o numero de ocorrencias do caractere na cadeia.

//Cabeçalho=========================

int contaCaractere(char* str, char c);


//Cabeçalho=========================

int main(void)
{

    char* str = "Rio de Janeiro";

    char c = 'i';

    int contCaractere = contaCaractere(str,c);

    printf(" %d caracteres '%c' foram encontrados na cadeia %s", contCaractere, c, str);

    return 0;
}


//Funções============================


int contaCaractere(char* str, char c)
{

    int i = 0;
    int contadorC = 0;
    while( str[i] != '\0')
    {
        if(str[i] == c)
        {
            contadorC++;
        }
    
        i++;
    }

    return contadorC;
}