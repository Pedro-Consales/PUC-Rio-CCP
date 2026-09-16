#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void){



    FILE * arqEntrada = fopen("autores.txt", "rt");
    if(arqEntrada == NULL){
        printf("Erro ao abrir o arquivo de entrada");
        exit(1);
    }

    char *vetor_titulo[100];
    char **vetor_autor;

    char titulo[127];
    char autor[127];
    for(int letra_atual = 'A'; letra_atual <= 'Z'; letra_atual++){

        printf("Letra autal = %c\n", letra_atual);

        int index_atual = letra_atual - 'A';

        printf("index_atual = %d\n", index_atual);
        
        while (fscanf(arqEntrada," %[^/]/%[^\n]\n", titulo, autor) == 2)
        {
            printf("\nTitluo e autor da vez = %s / %s\n", titulo, autor);
            
            if(titulo[0] == letra_atual){
                printf("Entrocntrei Titulo com A = %s\n", titulo);
                int tam_titulo = strlen(titulo);
                vetor_titulo[index_atual] = (char*)malloc((tam_titulo+1)*(sizeof(char)));
                strcpy(vetor_titulo[index_atual], titulo);
                index_atual++;
            }
        }
        index_atual = 0;
    }

    for(int i = 0; i < 7; i++){ 

        printf("Títuo %d = %s\n", i+1, vetor_titulo[i] );
    }
   

    return 0;
}