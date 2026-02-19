// Questão 08) Escreva uma função que recebe um vetor de strings com nomes de pessoas e retorne um novo 
// vetor de strings, alocado dinamicamente, onde cada elemento, também alocado dinamicamente, é o primeiro 
// nome de cada pessoa. Por exemplo, se for passado para a função o vetor {"Alberto Einsten", "Leonardo da 
// Vinci", "Alan Turing"}, sua função deve retornar o vetor {"Alberto", "Leonardo", "Alan"}.  
// Dicas:  - 
// Escreva uma função auxiliar que recebe uma string representando o nome completo de uma pessoa 
// e retorne uma nova string, alocada dinamicamente, com o primeiro nome da pessoa.  


// Questão 09) Escreva uma função para liberar a memória alocada dinamicamente na questão anterior. 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char** listaPrimeiroNome(char** listaNomesCompletos, int tamVetor);
char* retornaPrimeiroNome(char* nomeCompleto, int* tamPrimeiroNome);
void liberaMemoria(char** listaPrimNome, int tamVetor);


int main(void)
{
    int tamVetor = 3;
    char* listaNomeCompletos[3] = {"Alberto Einsten", "Leonardo da Vinci", "Alan Turing"};

    char** listaPrimoNome = listaPrimeiroNome(listaNomeCompletos, tamVetor);

    for(int i = 0; i < tamVetor; i++)
    {

        printf("%s / ", listaPrimoNome[i]);


    }


    liberaMemoria(listaPrimoNome, tamVetor);

    return 0;

}



char** listaPrimeiroNome(char** listaNomesCompletos, int tamVetor)
{

    char** listaPrimeiroNome = (char**)malloc(tamVetor*sizeof(char*));
    if(listaPrimeiroNome == NULL)
    {
        printf("Erro ao alocar memoria para a lista de primeiro nome");
        exit(1);
    }

    char* primeiroNome;
    int tamPrimeiroNome;
    int tamStr;
    for(int i = 0; i < tamVetor; i++)
    {
        tamStr = strlen(listaNomesCompletos[i]);

        primeiroNome = retornaPrimeiroNome(listaNomesCompletos[i], &tamPrimeiroNome); //decidi passar um ponteiro para armazenar o tamanho exato apenas do primeiro nome, assum eu ocupo menos memória
        

        listaPrimeiroNome[i] = (char*)malloc((tamPrimeiroNome+1)*sizeof(char));
        if(listaPrimeiroNome[i] == NULL)
        {
            printf("Erro ao alocar memoria para a lista de primeiro nome");
            exit(1);
        }

        strcpy(listaPrimeiroNome[i], primeiroNome);
    }

    return listaPrimeiroNome;

}

char* retornaPrimeiroNome(char* nomeCompleto, int* tamPrimeiroNome)
{
    int i = 0;
    int tam = 1;
    while (nomeCompleto[i] != ' ')
    {
        tam++;
        i++;
    }
    i--;
    tam--;

    *tamPrimeiroNome = tam;
    // retiro um pois o i parou no espaço e tenho que voltar para a ultima letra do nome;

    char* novaStr = (char*)malloc((tam+1)*sizeof(char));
    if(novaStr == NULL)
    {
        printf("Erro ao alocar memoria para a novaStr");
        exit(1);
    }
    
    int j;
    for( j = 0; j < tam; j++)
    {
        novaStr[j] = nomeCompleto[j];
    }

    novaStr[j] = '\0';

    return novaStr;

}

void liberaMemoria(char** listaPrimNome, int tamVetor)
{

    for(int i = 0; i < tamVetor; i++)
    {

        free(listaPrimNome[i]);

    }

    free(listaPrimNome);

}

