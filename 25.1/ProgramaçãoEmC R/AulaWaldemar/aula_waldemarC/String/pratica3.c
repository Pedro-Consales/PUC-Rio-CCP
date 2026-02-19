#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Enunciado: 

// Implemente uma função que recebe uma string como parametro e altere nessa string
// as ocorrencias de caracteres Maiusculos para Minusculos




//Cabeçalho=======================

void tominusuclo(char str[]);

//Cabeçalho=======================

int main(void)
{

    char str[] = "Pedro Consales Margaronis";

    
    printf("Nome ANTES da chamada da funcao: %s\n\n", str);


    tominusuclo(str);

    printf("Nome DEPOIS da chamada da funcao: %s", str);

    return 0;
}

//Funções=========================


void tominusuclo(char str[])
{

    int i = 0;
    while( str[i] != '\0')
    {
        if(str[i]>='A' && str[i]<= 'Z')
        {

            str[i] = str[i]+32;

        }

        i++;
    }


}