// Questão 16) Considere strings que contém o nome completo e a data de nascimento de uma 
// pessoa, separadas por dois pontos. Exemplos dessas strings são mostradas abaixo: 

// “Leonardo da Vinci: 15/04/1452”  
// “Albert Einstein: 14/03/1879” 

// Escreva uma função que recebe uma string nesse formato e retorne uma nova string, alocada 
// dinamicamente, que representa um login de usuário. O login deve ser formado pelas iniciais do 
// nome (em letras minúsculas), seguido de dois pontos, seguido do ano de nascimento. Por 
// exemplo, para as strings acima, sua função deve retornar “ldv:1452” e “ae:1879”, respectivamente.  

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


char* encurtaStr(char* str);

int main(void)
{

    char* str = "Leonardo da Vinci: 15/04/1452";

    char* abreviado = encurtaStr(str);

    printf("%s", abreviado);

    return 0;

}


char* encurtaStr(char* str)
{

    int tamStr = strlen(str);

    char letra;

    int indexUltimo = tamStr - 1;
    int contaCaracteres = 1; //Começa já contando o primeiro caractere
    int i = 0;
    while(str[i] != ':')
    {
        if(str[i] == ' ')
        {
            contaCaracteres++;
        }
        i++;
        
    }

    contaCaracteres++;


    while (str[indexUltimo] != '/')
    {
        contaCaracteres++;

        indexUltimo--;
    }
    indexUltimo++;


    char* novaStr = (char*)malloc((contaCaracteres+1)*sizeof(char));


    int k = 0;
    novaStr[k] = tolower(str[0]);
    k++;
    i = 0;
    while (str[i] != ':')
    {
        if(str[i] == ' ')
        {

            letra = tolower(str[i+1]);
            novaStr[k] = letra;
            k++;

        }
        i++;
    }
    novaStr[k] = str[i];
    k++;
    

    for(int m = indexUltimo; m < tamStr; m++)
    {
        novaStr[k] = str[m];
        k++;
    }

    novaStr[k] = '\0';

    return novaStr;

}