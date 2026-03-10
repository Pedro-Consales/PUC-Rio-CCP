// 1) Faça um programa para criar dois processos, o pai escreve seu pid e espera o
// filho terminar e o filho escreve o seu pid e termina.


#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

//Exemplo de saída
// pid do processo duplicado (filho): 65790
// pid processo PAI: 65789
// Esperando o processo filho terminar...

// pid do processo duplicado (filho): 0
// pid processo, FILHO: 65790

// Processo filho terminou. Posso continuar

// Return que recebi do filho COM WEXITSTATUS: 1
// Return que recebi do filho SEM WEXITSTATUS: 256

//O processo que está acontecendo agora já é esse código que está sendo executado.
int main(void){

    int pid;
    int myPid;
    int status;

    pid = fork(); //Ao fazer o fork, o processo é duplicado, e ambos os processos (pai e filho) continuam a execução a partir do ponto onde o fork foi chamado.
    //O valor retornado pelo fork é diferente para cada processo: o processo pai recebe o PID do processo filho (pid: 65790 no exemplo de saída), enquanto o processo filho recebe 0.
    //É basicamente assim. O pai no fork recebe o valor do filho para identificar, esse cara é pai então tem um id de algum processo (o filho)
    //Enquanto o filho recebe 0 porque essa é a convenção de retorno da função fork() no processo filho.
    
    // Agora os dois processos passam a executar concorrentemente.
    // O sistema operacional decide a ordem de execução entre eles.
    // Em máquinas com múltiplos núcleos, eles podem até executar em paralelo.

    printf("retorno do fork() neste processo: %d\n", pid);

    if(pid != 0){ //Se for o processo pai, ele entre nesse bloco

        myPid = getpid(); //getpid() é uma função que retorna o PID do processo atual, ou seja, o processo pai.

        printf("pid processo PAI: %d\n", myPid); //Repare que o processo pai é diferente do PID do filho, provavelmente menor

        printf("Esperando o processo filho terminar...\n\n");
        waitpid(pid, &status, 0); //waitpid é uma função que faz o processo pai esperar (não roda) até que o processo filho termine sua execução. 
        //O primeiro argumento é o PID do processo filho, o segundo argumento é um ponteiro para uma variável onde o status de término do processo filho será armazenado, e o terceiro argumento é usado para especificar opções adicionais (neste caso, 0 significa que não há opções).
        
        printf("\nProcesso filho terminou. Posso continuar\n\n");

        printf("Return que recebi do filho COM WEXITSTATUS: %d\n", WEXITSTATUS(status));
        printf("Return que recebi do filho SEM WEXITSTATUS: %d\n", status); 
        // O valor bruto de 'status' não é diretamente o código passado para exit().
        // Ele vem codificado com informações sobre o término do processo.
        // Por isso usamos WEXITSTATUS(status) para extrair corretamente o valor de saída.

    } else {

        myPid = getpid(); //getpid() é uma função que retorna o PID do processo atual, ou seja, o processo filho.
        printf("pid processo, FILHO: %d\n", myPid); // Repare que o processo filho é diferente do PID do pai, provavelmente maior
        exit(1);
    }
    return 0;
}