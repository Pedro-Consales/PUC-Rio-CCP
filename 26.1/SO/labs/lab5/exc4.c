#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define FILA_MAX 8
#define TOT_ELE 64

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_produce = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_consume = PTHREAD_COND_INITIALIZER;

int fila[FILA_MAX] = {-1, -1, -1, -1, -1, -1, -1, -1};


void *produtor(){
    int dado;

    for(int i = 0 ; i < TOT_ELE ; i++){

        pthread_mutex_lock(&mutex);

       
        while(fila[FILA_MAX-1] != -1){   
            pthread_cond_wait(&can_produce, &mutex);
        }

        int pos;
        for(pos = 0; pos < FILA_MAX && fila[pos] != -1; pos++);
        dado = rand() % 100;
        fila[pos] = dado;

        printf("dado %d escrito: %d\n", i, dado);

        pthread_cond_signal(&can_consume);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
    pthread_exit(NULL);
}

void *consumidor(){
    for(int i = 0 ; i < TOT_ELE ; i++){

        pthread_mutex_lock(&mutex);

       
        while(fila[0] == -1){     
            pthread_cond_wait(&can_consume, &mutex);
        }

        int lido = fila[0];
        for(int pos = 0; pos < FILA_MAX - 1; pos++){
            fila[pos] = fila[pos+1];
        }
        fila[FILA_MAX-1] = -1;

        pthread_cond_signal(&can_produce);
        pthread_mutex_unlock(&mutex);

        printf("%d dado lido: %d\n", i, lido);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main(void){

    pthread_t prod1, prod2, cons1, cons2;

    pthread_create(&prod1, NULL, produtor, NULL);
    pthread_create(&prod2, NULL, produtor, NULL);
    pthread_create(&cons1, NULL, consumidor, NULL);
    pthread_create(&cons2, NULL, consumidor, NULL);

    pthread_join(prod1, NULL);
    pthread_join(prod2, NULL);
    pthread_join(cons1, NULL);
    pthread_join(cons2, NULL);

    printf("\nfim\n");

    pthread_exit(NULL);
}