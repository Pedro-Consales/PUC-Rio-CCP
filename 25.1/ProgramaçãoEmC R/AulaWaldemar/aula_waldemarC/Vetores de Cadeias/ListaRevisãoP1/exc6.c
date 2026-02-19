// Questão 06) Escreva uma função que recebe duas strings e retorna se a segunda é prefixo da primeira. 
// Retorne 1 se for prefixo e 0 caso contrário. Considere que uma string vazia é prefixo da outra. Considere 
// também que duas strings iguais são prefixo uma da outra. 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int verfPrefix(char* strMaior, char* strMenor);


int main(void)
{

    char* str2 = "pro";
    char* str1  = "programacao";

    int verf = verfPrefix(str1, str2);

    if(verf == 1)
    {

        printf("%s EH prefixo de %s\n\n", str2, str1);

    }
    else{

        printf("%s NAO EH prefixo de %s\n\n", str2, str1);

    }

    str2 = "prog";
    str1  = "proximo";

    verf = verfPrefix(str1, str2);

    if(verf == 1)
    {

        printf("%s EH prefixo de %s\n\n", str2, str1);

    }
    else{

        printf("%s NAO EH prefixo de %s\n\n", str2, str1);

    }

}


int verfPrefix(char* str1, char* str2)
{

    int tamMenor;
    if(strlen(str1) > strlen(str2))
    {
        
        tamMenor = strlen(str2);

    }
    else if(strlen(str1) < strlen(str2))
    {
        
        tamMenor = strlen(str1);

    }
    else if(strlen(str1) == strlen(str2))
    {

        tamMenor = strlen(str1); //Tanto faz

    }
    
    for(int i = 0; i < tamMenor; i++)
    {   

        if(str1[i] != str2[i])
        {
            return 0;
        }
       
    }

    return 1;
}
