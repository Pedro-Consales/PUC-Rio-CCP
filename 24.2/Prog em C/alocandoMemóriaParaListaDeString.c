#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_strings = 3;  // Definindo o número de strings
    int tamanho_max = 50; // Tamanho máximo de cada string (incluindo o '\0')

    // Alocando memória para o array de ponteiros para char
    char **lista = (char **)malloc(num_strings * sizeof(char *));

    // Verificando se a memória foi alocada corretamente
    if (lista == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Alocando memória para cada string
    for (int i = 0; i < num_strings; i++) {
        lista[i] = (char *)malloc(tamanho_max * sizeof(char));
        if (lista[i] == NULL) {
            printf("Erro ao alocar memória para a string %d.\n", i + 1);
            return 1;
        }
    }

    // Atribuindo valores às strings
    strcpy(lista[0], "Maçã");
    strcpy(lista[1], "Banana");
    strcpy(lista[2], "Laranja");

    // Imprimindo as strings
    for (int i = 0; i < num_strings; i++) {
        printf("Fruta %d: %s\n", i + 1, lista[i]);
    }

    // Liberando a memória alocada
    for (int i = 0; i < num_strings; i++) {
        free(lista[i]); // Liberando cada string
    }
    free(lista); // Liberando o array de ponteiros

    return 0;
}
