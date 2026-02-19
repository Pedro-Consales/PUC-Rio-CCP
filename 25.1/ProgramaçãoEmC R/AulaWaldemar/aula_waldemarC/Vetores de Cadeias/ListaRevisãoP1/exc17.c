// Questão 17) Escreva uma função que recebe uma string com palavras separadas por espaços 
// em branco e retorne um novo vetor de strings, alocado dinamicamente, onde cada elemento é 
// uma palavra da string original, também alocada dinamicamente. Por exemplo, se a função receber 
// a string “Este foi um teste”, a função deve retornar um vetor com 4 strings: 
// Sua função deve retornar o endereço do vetor de strings e preencher o endereço recebido com o 
// número de elementos do vetor, seguindo o protótipo: 
// char** split (char* original, int* pNumElem);

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char** split (char* original, int* pNumElem);


int main(void)
{

    char* original = "Esse foi um teste";
    int pNumElem;

    char** novoVetor = split(original, &pNumElem);

    for(int i = 0; i < pNumElem; i++)
    {
        printf("%s / ", novoVetor[i]);


    }

    return 0;
}


char** split (char* original, int* pNumElem)
{
    int contaPalavras = 1;

    int i = 0;
    while (original[i] != '\0')
    {
        if(original[i] == ' ')
        {
            contaPalavras++;
        }
        i++;
    }
    
    *pNumElem = contaPalavras;
    
    char** listaSplited = (char**)malloc(contaPalavras*sizeof(char*));

    int inicio = 0;
    int iPalavraAtual = 0;
    int tamStr = strlen(original);
    for(int i = 0; i < tamStr; i++)
    {
        int tamPalavra;
        if(original[i] == ' ' || original[i] == '\0')
        {
            
            tamPalavra = i - inicio;

        }

        listaSplited[iPalavraAtual] = (char*)malloc((tamPalavra+1)*sizeof(char));
        if (listaSplited[iPalavraAtual] == NULL) {
            printf("Erro ao alocar memória para a palavra.\n");
            exit(1);
        }

        strcpy(listaSplited[iPalavraAtual], &original[inicio]);
        listaSplited[iPalavraAtual][tamStr] = '\0';


        iPalavraAtual++;
        inicio = i + 1;
    }
    *pNumElem = iPalavraAtual;

    return listaSplited;
}

//ERRAAADOOO
