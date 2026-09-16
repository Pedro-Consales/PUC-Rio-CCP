
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OPERACOES 10000
#define MAX_KEY       999
#define MIN_KEY       0


//escreve n operações aleatórias no log.txt
void gerar_operacoes(int n) {
    FILE *fp = fopen("log.txt", "w");
    if (fp == NULL) {
        perror("Erro: Não foi possível abrir log.txt para escrita");
        exit(1);
    }

    srand(time(NULL));  // aleatório referente ao temp

    for (int i = 0; i < n; i++) {
        int op  = rand() % 2; // 0 = READ, 1 = WRITE
        int key = (rand() % (MAX_KEY - MIN_KEY + 1)) + MIN_KEY; 

        if (op == 0) {

            fprintf(fp, "R, %d\n", key);
        } else {

            int value = (rand() % 4991) + 10; 
            fprintf(fp, "W, %d, %d\n", value, key);
        }
    }

    fclose(fp);
    printf("log.txt gerado com %d operações.\n", n);
}


int main() {
    gerar_operacoes(NUM_OPERACOES);
    return 0;
}