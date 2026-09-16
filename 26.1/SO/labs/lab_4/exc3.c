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


        if(pid == 0){//Esotu no processo filho

            close(fd[0]);
            dup2(fd[1], 1); // stdout vira a escrita do pipe
            execlp("ps", "ps", NULL);

        }
        else if(pid > 0){//Esotu no processo pai

            int pid2 = fork();

            if(pid2 == 0){//Estou no processo filho 2

                close(fd[1]);
                dup2(fd[0], 0); // stdin vira a leitura do pipe
                execlp("wc", "wc", NULL);


            }
            else if(pid2 > 0){//Estou no preocesso pai
                close(fd[0]);
                close(fd[1]);
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