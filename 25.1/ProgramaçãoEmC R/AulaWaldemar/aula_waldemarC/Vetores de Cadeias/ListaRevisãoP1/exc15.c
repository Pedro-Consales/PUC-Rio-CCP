// Questão 15) Escreva uma função que inverte uma string sem criar uma 
//cópia da string original. Se sua função 
// receber a string “pontificia”, a string original 
//deve ser alterada para passar a ser “aicifitnop”. 


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inverteStr(char* str);

int main(void)
{
    char str[100] = "pontificia";

    printf("str antes da funcao %s\n\n", str);

    inverteStr(str);

    printf("str depois da funcao %s", str);
    
    return 0;
}

void inverteStr(char* str)
{
    int tamStr = strlen(str);
    char letraFinal;
    char letraInicio;

    int indicieOposto = tamStr-1;
    int index = 0;
    
    while(index < indicieOposto)
    {

        letraFinal = str[indicieOposto];
        letraInicio = str[index];

        str[index] = letraFinal;
        str[indicieOposto] = letraInicio;

        index++;
        indicieOposto--;
    }
}

