#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>



int main(void)
{
    int pid = fork();


    if(pid == 0)
    {
        while(1){
            printf("Sou o filho 1\n");
            sleep(1);
            
        }
    }
    else{

        int pid_filho_um = pid;
        int pid_dois = fork();
        

        int total = 10;

        if(pid_dois == 0)
        {
            while(1){
                printf("Sou o filho 2\n");
                sleep(1);
            }
            
        }
        else{
            int pid_filho_dois = pid_dois;

            kill(pid_filho_dois, SIGSTOP);

            int ativo = pid_filho_um;

            for(int cont = 0; cont<total; cont++){
                sleep(2);
                if(ativo == pid_filho_um)
                {
                    kill(pid_filho_um, SIGSTOP);
                    kill(pid_filho_dois, SIGCONT);
                    ativo = pid_filho_dois;
                }
                else if(ativo == pid_filho_dois)
                {
                    kill(pid_filho_dois, SIGSTOP);
                    kill(pid_filho_um, SIGCONT);
                    ativo = pid_filho_um;
                }
                
            }
        
        }


        kill(pid, SIGKILL);
        kill(pid_dois, SIGKILL);

        waitpid(pid, NULL, 0);
        waitpid(pid_dois, NULL, 0);

    }

}