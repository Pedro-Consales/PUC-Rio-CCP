#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Encunciado: Faça uma função que reveba uma string Martin Luther King e 
//retorne uma nova cadeia 'King M.L.'

char* retornaReduzido(char* str);

int main(void)
{

    char str[] = "Martin Luther King";

    char* novaStr = retornaReduzido(str);

    printf("Nova str: %s", novaStr);

}


char* retornaReduzido(char* str)
{

    int tamanhoInicialStr = strlen(str);
    int index = 0;
    int buffer_index = tamanhoInicialStr-1;

    char* novaStr = (char*)malloc((tamanhoInicialStr+1)*sizeof(char));

    while (str[buffer_index] != ' ')
    {
        buffer_index--;
    }

    buffer_index++;
    index = buffer_index;

    int i = 0;
    while(str[buffer_index] != '\0')
    {

        novaStr[i] = str[buffer_index];
        i++;
        buffer_index++;

    }
    novaStr[i] = ' ';
    i++;

    int j = 0;
    while(j != index)
    {
        if(str[j] >= 'A' && str[j]<= 'Z')
        {

            novaStr[i] = str[j];
            i++;
            novaStr[i] = '.';
            i++;
        }
        j++;
    }

    novaStr[i] = '\0';
    
    return novaStr;
}


