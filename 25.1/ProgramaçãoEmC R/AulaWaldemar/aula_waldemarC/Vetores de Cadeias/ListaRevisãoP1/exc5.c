// Escreva uma função para criar uma nova cadeia de caracteres sem repetição em sequência dos 
// caracteres de uma cadeia fornecida. Por exemplo, dado "AAnnnaa", a função cria e retorna a cadeia "Ana". 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* reorgNome(char* str);

int main(void)
{

    char* str = "AAnnnaa";


    char* nvStr = reorgNome(str);

    printf("%s", nvStr);

    return 0;

}


char* reorgNome(char* str)
{


    char bufferLetra;
    int tam = strlen(str);
    int contaLetras = 1; //Pois o primeiro já é considerado.

    bufferLetra = str[0];
    for(int i = 0; i < tam; i++)
    {
        
        if(bufferLetra == str[i])
        {
            continue;
        }
        else
        {
            bufferLetra = str[i];
            contaLetras++;
        }
        
    }

    char* novaStr = (char*)malloc((contaLetras+1)*sizeof(char));
    if(novaStr == NULL)
    {
        printf("Erro ao alocar memoria para novaStr");
        exit(1);
    }

    int j = 1;
    bufferLetra = str[0];

    novaStr[0] = bufferLetra;// Ja guarda a primeira letra na string.
    for(int i = 0; i < tam; i++)
    {
        
        if(bufferLetra != str[i])
        {
            bufferLetra = str[i];
            novaStr[j] = bufferLetra;
            j++;
        }
        
    }

    novaStr[j] = '\0';
    return novaStr;
}