#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>



int main(void){

    int pid = fork();

    if(pid == 0){
    
        int i = 1;
        while (1)
        {
            printf("Filho printou %d vez\n", i);


            i++;
        }
        

    }
    else if(pid > 0){
        
        while(1){
            sleep(2); // Espera o filho iniciar
            kill(pid, SIGSTOP);  // manda sinal pro filho parar.
            sleep(2); // Durante a pausa
            kill(pid, SIGCONT);  // manda sinal pro filho parar.
        }

    }
    else{
        printf("Erro");
        exit(1);
    }

    return 0;
}