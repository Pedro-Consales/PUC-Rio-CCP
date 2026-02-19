// // Questão 14) Escreva uma função que recebe um vetor de palavras (strings) e uma palavra (string) e retorna 
// // o índice do vetor em que a palavra esteja. Se a palavra não for encontrada, a função deve retornar -1. 

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>


// int verfExiste(char** listaDeStr, int tamLista, char* str);


// int main(void)
// {

//     int tamLista = 4;
//     char* listaDeStr[4] = {"pedro", "lucianna", "lucio", "aninha"};
//     char* str = "lucianna";

//     int verf = verfExiste(listaDeStr, tamLista, str);

//     printf("%d", verf);

//     return 0;

// }


// int verfExiste(char** listaDeStr, int tamLista, char* str)
// {

//     int tamStr = strlen(str);


//     for(int i = 0; i < tamLista; i++)
//     {
//         int tamStrLista = strlen(listaDeStr[i]);


//         if(tamStr != tamStrLista)
//         {
//             continue;

//         }


//         for(int j = 0; j < tamStr; j++)
//         {
//             if(listaDeStr[i][j] != str[j])
//             {

//                return -1;

//             }
            
//         }
//         return i;   
//     }
// }






/// Ou com a função strcmp()



// Questão 14) Escreva uma função que recebe um vetor de palavras (strings) e uma palavra (string) e retorna 
// o índice do vetor em que a palavra esteja. Se a palavra não for encontrada, a função deve retornar -1. 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int verfExiste(char** listaDeStr, int tamLista, char* str);


int main(void)
{

    int tamLista = 4;
    char* listaDeStr[4] = {"pedro", "lucianna", "lucio", "aninha"};
    char* str = "pedro";

    int verf = verfExiste(listaDeStr, tamLista, str);

    printf("%d", verf);

    return 0;

}


int verfExiste(char** listaDeStr, int tamLista, char* str)
{

    int tamStr = strlen(str);

    int verf;
    for(int i = 0; i < tamLista; i++)
    {
        int tamStrLista = strlen(listaDeStr[i]);


        if(tamStr != tamStrLista)
        {
            continue;

        }

        verf = strcmp(listaDeStr[i], str);

        if(verf == 0)
        {
            return i;
        }

    }

    return -1;
}