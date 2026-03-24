#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int segmento, pid, status;
    int *a[3] , *b[3], *c[3];

    int temp1[3][3] = {
        {5,2,8}, 
        {8,2,6}, 
        {7,7,9}
    }, 
    temp2[3][3] = {
        {9,8,7}, 
        {6,5,10}, 
        {5,2,3}
    };

    segmento = shmget (IPC_PRIVATE, sizeof(int) * 9, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

    a[0] = (int*) shmat(segmento,0,0);
    a[1] = a[0] + 3;
    a[2] = a[0] + 6;

    printf("matriz a:\n");
    for (int i = 0; i<3; i++){
        printf("[");
        for(int j = 0; j<3; j++){
            a[i][j] = temp1[i][j];
            printf(" %d ",a[i][j]);
        }
        printf("]\n");
    }

    segmento = shmget (IPC_PRIVATE, sizeof(int) * 9, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

    b[0] = (int*) shmat(segmento,0,0);
    b[1] = b[0] + 3;
    b[2] = b[0] + 6;

    printf("matriz b:\n");
    for (int i = 0; i<3; i++){
        printf("[");
        for(int j = 0; j<3; j++){
            b[i][j] = temp2[i][j];
            printf(" %d ",b[i][j]);
        }
        printf("]\n");
    }

    segmento = shmget (IPC_PRIVATE, sizeof(int) * 9, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

    c[0] = (int*) shmat(segmento,0,0);
    c[1] = c[0] + 3;
    c[2] = c[0] + 6;

    for(int i = 0; i<3; i++){
        if( (pid = fork()) < 0){
            printf("Erro na criação do processo\netapa: %d\n", i);
            exit(-2);
        }
        if(pid == 0){    // filho
            printf(" fliho %d fazendo linha %d\n", i,i);
            for(int j = 0; j<3; j++){
                c[i][j] = a[i][j] + b[i][j];
            }
            exit(0);
        }
    }
    waitpid(pid, &status, 0);

    printf("matriz c:\n");
    for (int i = 0; i<3; i++){
        printf("[");
        for(int j = 0; j<3; j++){
            printf(" %d ",c[i][j]);
        }
        printf("]\n");
    }
}