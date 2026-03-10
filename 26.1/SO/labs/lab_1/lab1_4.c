// 4) Modifique o programa anterior para que o filho execute um programa elaborado
// por você, que mande imprimir uma mensagem qualquer no vídeo, por exemplo,
// “alo mundo”. Em seguida altere o programa do item 4 para o filho executar o
// programa echo da shell.


#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


//Conclusão: Vemos que o endereço dos vetores é visualemtne igual (0x16F57AA80), mas na verdade eles não estão compartilhando o mesmo vetor.
// O fork() cria uma cópia do processo, e cada processo tem seu próprio espaço de memória. Portanto, o pai e o filho têm vetores separados, mesmo que os endereços pareçam iguais. 
// As alterações feitas no vetor do filho não afetam o vetor do pai, e vice-versa.




//O processo que está acontecendo agora já é esse código que está sendo executado.
int main(void){

    int pid;
    int myPid;
    int status;


    pid = fork(); //Ao fazer o fork, o processo é duplicado, e ambos os processos (pai e filho) continuam a execução a partir do ponto onde o fork foi chamado.

    if(pid != 0){ //Se for o processo pai, ele entre nesse bloco
        

        printf("\n========== Bloco do Pai ==========\n\n");

        printf("retorno do fork() neste processo: %d\n", pid);

        myPid = getpid(); 

        printf("pid processo PAI: %d\n", myPid);

        printf("Esperando o processo filho terminar...\n\n");
        waitpid(pid, &status, 0); 
        
        printf("\nProcesso filho terminou. Posso continuar\n\n");

        printf("Return que recebi do filho COM WEXITSTATUS: %d\n", WEXITSTATUS(status));
        printf("Return que recebi do filho SEM WEXITSTATUS: %d\n", status); 


        printf("========== Bloco do Pai (Fim) ==========\n\n");

    } else {


        printf("\n========== Bloco do Filho ==========\n\n");

        printf("retorno do fork() neste processo: %d\n", pid);

        myPid = getpid(); //getpid() é uma função que retorna o PID do processo atual, ou seja, o processo filho.
        printf("pid processo, FILHO: %d\n", myPid); // Repare que o processo filho é diferente do PID do pai, provavelmente maior
        
        //printf("Resposta do execl():\n");
        // execl("./alou", "alou", NULL); // A função execl() é usada para substituir o processo atual (o processo filho) por um novo programa. O primeiro argumento é o caminho para o programa a ser executado, o segundo argumento é o nome do programa (que geralmente é o mesmo que o caminho), e o terceiro argumento é um ponteiro nulo para indicar o final da lista de argumentos. Neste caso, o processo filho irá executar o programa "alou", que deve estar localizado no mesmo diretório do programa principal.
        // perror("exec falhou"); // Se a função execl() falhar, ela retorna -1 e define errno para indicar o erro. A função perror() é usada para imprimir uma mensagem de erro correspondente ao valor de errno. Neste caso, se a execução do programa "alou" falhar, será exibida uma mensagem de erro indicando o motivo da falha.
        
        //Teste mandatório com echo
        printf("Resposta do execl() para o echo:\n");
        execlp("echo", "echo", "alou", NULL); // A função execlp() é semelhante à execl(), mas ela procura o programa a ser executado no PATH do sistema, ou seja, nos diretórios listados na variável de ambiente PATH. Neste caso, o processo filho irá executar o comando "echo" com o argumento "alou". O comando "echo" é um utilitário de shell que simplesmente imprime os argumentos fornecidos para ele. Portanto, se a execução for bem-sucedida, o processo filho imprimirá "alou" no terminal.
        perror("exec echo falhou");

        printf("========== Bloco do Filho (Fim) ==========\n\n");
        exit(1); // O processo filho chama exit(1) para terminar sua execução. O valor 1 é um código de saída que indica que o processo terminou com um erro. No entanto, como o processo filho já tentou executar o programa "alou" usando execl(), se a execução for bem-sucedida, o código após a chamada de execl() não será executado, e o processo filho será substituído pelo programa "alou". Se a execução falhar, o processo filho continuará a execução e chamará exit(1) para terminar com um código de erro.
    }
    return 0;
}