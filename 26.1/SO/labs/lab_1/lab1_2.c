// 2) Agora, usando a mesma estrutura de processos pai e filho, declare uma
// variável visível ao pai e ao filho, no pai inicialize a variável com1 e imprima seu
// valor antes do fork(). No filho, altere o valor da variável para 5 e imprima o seu
// valor antes do exit(). Agora, no pai, imprima novamente o valor da variável após o
// filho ter alterado a variável - após a waitpid(). Justifique os resultados obtidos.



#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

//Exemplo de saída
// x antes do fork(): 1
// retorno do fork() neste processo: 67019
// pid processo PAI: 67011
// Esperando o processo filho terminar...

// retorno do fork() neste processo: 0
// pid processo, FILHO: 67019
// x no filho antes do exit(): 5

// Processo filho terminou. Posso continuar

// x no pai após o waitpid(): 1

// Return que recebi do filho COM WEXITSTATUS: 1
// Return que recebi do filho SEM WEXITSTATUS: 256




//O processo que está acontecendo agora já é esse código que está sendo executado.
int main(void){

    int pid;
    int myPid;
    int status;
    int x = 1; // Após o fork(), o pai e o filho terão cópias separadas de x.


    printf("x antes do fork(): %d\n", x); // O valor de x é 1 antes do fork().
    pid = fork(); //Ao fazer o fork, o processo é duplicado, e ambos os processos (pai e filho) continuam a execução a partir do ponto onde o fork foi chamado.

    printf("retorno do fork() neste processo: %d\n", pid);

    if(pid != 0){ //Se for o processo pai, ele entre nesse bloco


        myPid = getpid(); 

        printf("pid processo PAI: %d\n", myPid);

        printf("Esperando o processo filho terminar...\n\n");
        waitpid(pid, &status, 0); 
        
        printf("\nProcesso filho terminou. Posso continuar\n\n");

        printf("x no pai após o waitpid(): %d\n\n", x); // O valor de x no processo pai permanece 1, pois o fork() cria uma cópia do processo, e as alterações feitas no processo filho não afetam o processo pai.

        printf("Return que recebi do filho COM WEXITSTATUS: %d\n", WEXITSTATUS(status));
        printf("Return que recebi do filho SEM WEXITSTATUS: %d\n", status); 


    } else {

        myPid = getpid(); //getpid() é uma função que retorna o PID do processo atual, ou seja, o processo filho.
        printf("pid processo, FILHO: %d\n", myPid); // Repare que o processo filho é diferente do PID do pai, provavelmente maior
        
        x = 5; // O valor de x é alterado para 5 no processo filho
        printf("x no filho antes do exit(): %d\n", x); // O valor de x é 5 no processo filho antes do exit().
        exit(1);
    }
    return 0;
}