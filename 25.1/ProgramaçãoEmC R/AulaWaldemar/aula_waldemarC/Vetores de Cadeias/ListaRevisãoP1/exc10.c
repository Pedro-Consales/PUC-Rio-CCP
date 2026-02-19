// // Questão 10) Escreva uma função que recebe um vetor de inteiros v e a quantidade de elementos n nesse 
// // vetor e cria um vetor de ponteiros para char, contendo strings com a seguinte regra de formação. Se v[i] for 
// // par, a string deverá conter v[i] vezes a letra ‘A’. Por outro lado, se v[i] for ímpar, a string deverá conter v[i] 
// // vezes a letra ‘a’. Como exemplo, para um vetor de entrada v = { 2, 4, 3, 1 }, é esperado que seja criado 
// // dinamicamente um vetor de char* contendo as strings “AA”, “AAAA”, “aaa” e “a”. 


// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>


// char** vetorDeA(int* v, int qtdEleV);


// int main(void)
// {
    
//     int tamVetor =  4;
//     int v[4] = { 2, 4, 3, 1 };

//     char** vetD_A = vetorDeA(v, tamVetor);

//     for(int i = 0; i < tamVetor; i++)
//     {

//         printf("%s / ", vetD_A[i]);


//     }


//     for(int i = 0; i < tamVetor; i++)
//     {

//         free(vetD_A[i]);


//     }
//     free(vetD_A);

//     return 0;

// }


// char** vetorDeA(int* v, int qtdEleV)
// {
//     char* bufferStr;
//     char** vetorD_A = (char**)malloc(qtdEleV*sizeof(char**));
//     if(vetorD_A == NULL)
//     {
//         printf("Erro ao alicar a memoria para o vetor de A");
//         exit(1);
//     }
//     for(int i = 0; i < qtdEleV; i++)
//     {
//         if(v[i] % 2 == 0)
//         {
//             vetorD_A[i] = (char*)malloc((v[i]+1)*sizeof(char));
//             if(vetorD_A[i] == NULL)
//             {
//                 printf("Erro ao alicar a memoria para o vetor de A no indicie %d", i);
//                 exit(1);
//             }
            
//             int j;
//             for(j = 0; j < v[i]; j++)
//             {
//                 vetorD_A[i][j] = 'A';

//             }
//             vetorD_A[i][j] = '\0';

//         }
//         else if(v[i] % 2 != 0)
//         {

//             vetorD_A[i] = (char*)malloc((v[i]+1)*sizeof(char));
//             if(vetorD_A[i] == NULL)
//             {
//                 printf("Erro ao alicar a memoria para o vetor de A no indicie %d", i);
//                 exit(1);
//             }
            
//             bufferStr = (char*)malloc((v[i]+1)*sizeof(char));
//             if(bufferStr == NULL)
//             {
//                 printf("Erro ao alicar a memoria para bufferStr");
//                 exit(1);
//             }

//             int j;
//             for(j = 0; j < v[i]; j++)
//             {
//                 vetorD_A[i][j] = 'a'; // Essa lógica é mais eficiente do que guardar em uma variável buffer e depois copiar ela pois, já que temos o espaço já alocado para cada cadeia de caractere, não precisamos alocar outro como buffer e depois copiar esse buffer para a pos. Basta apenas dentro do elemento da vez, copiar caractere por caractere.

//             }
//             vetorD_A[i][j] = '\0';
//         }
//     }
//     return vetorD_A;
// }



//====================== Outra forma mais otimizada ainda de fazer


// Questão 10) Escreva uma função que recebe um vetor de inteiros v e a quantidade de elementos n nesse 
// vetor e cria um vetor de ponteiros para char, contendo strings com a seguinte regra de formação. Se v[i] for 
// par, a string deverá conter v[i] vezes a letra ‘A’. Por outro lado, se v[i] for ímpar, a string deverá conter v[i] 
// vezes a letra ‘a’. Como exemplo, para um vetor de entrada v = { 2, 4, 3, 1 }, é esperado que seja criado 
// dinamicamente um vetor de char* contendo as strings “AA”, “AAAA”, “aaa” e “a”. 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char** vetorDeA(int* v, int qtdEleV);


int main(void)
{
    
    int tamVetor =  4;
    int v[4] = { 2, 4, 3, 1 };

    char** vetD_A = vetorDeA(v, tamVetor);

    for(int i = 0; i < tamVetor; i++)
    {

        printf("%s / ", vetD_A[i]);


    }


}


char** vetorDeA(int* v, int qtdEleV)
{
    char letra;
    char** vetorD_A = (char**)malloc(qtdEleV*sizeof(char**));
    if(vetorD_A == NULL)
    {
        printf("Erro ao alicar a memoria para o vetor de A");
        exit(1);
    }

    for(int i = 0; i < qtdEleV; i++)
    {   
        vetorD_A[i] = (char*)malloc((v[i]+1)*sizeof(char));
        if(v[i] % 2 == 0)
        {
            letra = 'A';
            
        }
        else
        {
            letra = 'a';
        }

        int j;
        for(j = 0; j < v[i]; j++)
        {
            vetorD_A[i][j] = letra; 

        }
        vetorD_A[i][j] = '\0';
    }
    return vetorD_A;
}
