#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>



int main(void){
    
    int fd[2];

    int res = pipe(fd);
    if (res < 0)
    {
        puts("Erro ao abrir os pipes");
        exit(-1);
    }

    int pid = fork();


    if(pid == 0){//Esotu no processo filho 1 (leitor 1)

        close(fd[1]);

        // leitor
        int val;
        for(int i = 0; i < 5; i++){
            read(fd[0], &val, sizeof(int)); // lê um número do pipe
            printf("Leitor 1 leu: %d\n", val);
            sleep(2); // dorme 2 segundos (dobro do escritor)
        }


    }
    else if(pid > 0){//Esotu no processo pai

        int pid2 = fork();

        if(pid2 == 0){//Estou no processo filho 2 (leitor 2)

            close(fd[1]);

            // leitor
            int val;
            for(int i = 0; i < 5; i++){
                read(fd[0], &val, sizeof(int)); // lê um número do pipe
                printf("Leitor 2 leu: %d\n", val);
                sleep(2); // dorme 2 segundos (dobro do escritor)
            }


        }
        else if(pid2 > 0){//Estou no preocesso pai
           int pid3 = fork();

            if(pid3 == 0){//Estou no filho 3 (escritor)
                close(fd[0]);
                // escritor
                for(int i = 0; i < 5; i++){
                    write(fd[1], &i, sizeof(int)); // escreve o número i no pipe
                    printf("Escritor escreveu: %d\n", i);
                    sleep(1); // dorme 1 segundo
                }
            }
            else if(pid3>0){//Estou no pai
                
                close(fd[0]);
                close(fd[1]);
                wait(NULL);
                wait(NULL);
                wait(NULL); // um para cada filho
            }
            else{//Erro
                exit(-1);
            }

        }
        else{//Erro
            exit(-1);
        }


    }
    else{//Erro
        exit(-1);
    }



}