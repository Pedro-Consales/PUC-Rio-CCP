#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// Uma função que codifique uma mensagem, dada uma chave inteira n. Nessa codificação,
//  todas as ocorrências de letras minúsculas, letras maiúsculas e dígitos devem ser 
//  mapeadas para os caracteres deslocados de n. Por exemplo, se a chave 
// for n = 2, a letra 'a' é mapeada para 'c' , a letra 'A' é
// mapeada para 'C' e o dígito 'O' é mapeado para '2' , e assim
// por diante, com deslocamento cíclido: a letra 'z', no exemplo acima, 
// é mapeada para a letra 'b'. Sua função deve receber como parâmetros a 
// mensagem original e a chave n, e retornar uma nova cadeia com a mensagem criptografada.

char* encrypt(char* str);

int main(void)
{

    char str[] = "aZ089";

    char* novaStr = encrypt(str);

    printf("Decriptografada: %s\n\n", str);

    printf("Criptografada %s", novaStr);

}

char* encrypt(char* str, int n)
{
    int i = 0;

    int tamanhoStr = strlen(str);
    char* novaStr = (char*)malloc((tamanhoStr+1)*sizeof(char));

    if(novaStr == NULL)
    {

        printf("Erro ao alocar memoria para a novaStr");
        return;

    }

    while(str[i] != '\0')
    {
        


    }
        


    novaStr[i] = '\0';

    return novaStr;

}