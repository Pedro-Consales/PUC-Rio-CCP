#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define FILA_MAX 8;
#define TOT_ELE 64;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_produce;
can_produce = PTHREAD_COND_INITIALIZER;

int fila[FILA_MAX] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};



void produtor(){
    for(int i = 0 ; i < TOT_ELE ; i++){

        if(fila[8] == 8){
            pthread_cond_wait(&can_produce, &mutex);
        }

        for(int pos = 0; pos < FILA_MAX; pos++){
            if(fila[pos] == NULL){
                coloco = 1;
                fila[pos] = rand();
            }
        }
        sleep(1);
    }
}

void consumidor(){
    for(int i = 0 ; i < TOT_ELE ; i++){
        if(fila[0] != NULL){
            pthread_mutex_lock(&mutex)
            int lido = fila[0];
             for(int pos = 0; pos < FILA_MAX - 1; pos++){
                fila[pos] = fila[pos] + 1;
            }
            fila[FILA_MAX-1] = NULL;
            
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&can_produce);

        }
    }
}

int main(void){

}