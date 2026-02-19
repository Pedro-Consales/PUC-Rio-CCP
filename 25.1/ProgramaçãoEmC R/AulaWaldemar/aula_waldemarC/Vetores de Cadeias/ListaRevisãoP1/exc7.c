// Questão 07) Escreva uma função que dado um nome, retorna uma nova cadeia com o último sobrenome. 
// Por exemplo, dado "Carlos Drumond de Andrade", a nova cadeia deve ser "Andrade". 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* ultimoNome(char* nome);


int main(void)
{


    char* nome = "Carlos Drumond de Andrade";

    char* novoNome = ultimoNome(nome);

    printf("O ultimo nome eh: %s", novoNome);

    free(novoNome);


}



char* ultimoNome(char* nome)
{

    int tamNome = strlen(nome);

    int i = tamNome-1;

    int indexUltimoNome;
    while (nome[i] != ' ' )
    {   
        i--;
    }
    
    i++; //para pular o espaço.

    indexUltimoNome = i;

    
    int tamNovaStr = tamNome-i;

    char* novaStr = (char*)malloc((tamNovaStr+1)*sizeof(char));
    if(novaStr == NULL)
    {
        printf("Erro ao alocar memoria para a novastr");
        exit(1);
    }

    int j;
    for(j = 0; j < tamNovaStr; j++)
    {

        novaStr[j] = nome[indexUltimoNome];
        indexUltimoNome++;

    }
    novaStr[j] = '\0';


    return novaStr;
}