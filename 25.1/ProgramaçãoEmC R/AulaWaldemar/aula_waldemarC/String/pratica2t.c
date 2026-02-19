#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Enunciado:

// Implemente uma função que receba uma string como parametro e retorne como resultado
// o numero de vogais presente nessa string;





//Cabeçalho============================

int contaVogais(char*str);
//Cabeçalho============================



int main(void)
{

    char* str = "Pedro";


    int contadorVogais = contaVogais(str);


    printf("Existem %d vogais na str %s", contadorVogais, str);



}


//Função============================


int contaVogais(char*str)
{

    int i = 0;
    int contVogais = 0;
    while(str[i] !='\0')
    {

        if( str[i] == 'A' || str[i] == 'a' ||
            str[i] == 'E' || str[i] == 'e' ||
            str[i] == 'I' || str[i] == 'i' ||
            str[i] == 'O' || str[i] == 'o' ||
            str[i] == 'U' || str[i] == 'u')
        {

            contVogais++;

        }
        i++;
    }

    return contVogais;
}