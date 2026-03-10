// 3) Use o programa anterior para ler e ordenar um vetor de 10 posições. O filho
// ordena o vetor e o pai exibe os dados do vetor antes do fork() e depois do
// waitpid(). Eles usarão o mesmo vetor na memória? Justifique.

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

// x antes do fork(): 1
// Vetor antes do fork(): { 7 2 9 4 0 6 1 8 3 5 } -->  Com endereço: 0x16F57AA80


// ========== Bloco do Pai ==========

// retorno do fork() neste processo: 68912
// pid processo PAI: 68911
// Esperando o processo filho terminar...


// ========== Bloco do Filho ==========

// retorno do fork() neste processo: 0
// pid processo, FILHO: 68912
// x no filho antes do exit(): 5
// Vetor NO FILHO antes do exit(): { 0 1 2 3 4 5 6 7 8 9 } -> Com endereço: 0x16F57AA80 

// ========== Bloco do Filho (Fim) ==========


// Processo filho terminou. Posso continuar

// x no pai após o waitpid(): 1

// Vetor no pai após o waitpid(): { 7 2 9 4 0 6 1 8 3 5 } --> Com endereço: 0x16F57AA80 

// Return que recebi do filho COM WEXITSTATUS: 1
// Return que recebi do filho SEM WEXITSTATUS: 256
// ========== Bloco do Pai (Fim) ==========


//Conclusão: Vemos que o endereço dos vetores é visualemtne igual (0x16F57AA80), mas na verdade eles não estão compartilhando o mesmo vetor.
// O fork() cria uma cópia do processo, e cada processo tem seu próprio espaço de memória. Portanto, o pai e o filho têm vetores separados, mesmo que os endereços pareçam iguais. 
// As alterações feitas no vetor do filho não afetam o vetor do pai, e vice-versa.

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int vetor[], int low, int high) {
    int pivot = vetor[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (vetor[j] < pivot) {
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i + 1], &vetor[high]);
    return i + 1;
}

void quickSort(int vetor[], int low, int high) {
    if (low < high) {
        int pi = partition(vetor, low, high);
        quickSort(vetor, low, pi - 1);
        quickSort(vetor, pi + 1, high);
    }
}


//O processo que está acontecendo agora já é esse código que está sendo executado.
int main(void){

    int pid;
    int myPid;
    int status;
    int x = 1; // Após o fork(), o pai e o filho terão cópias separadas de x.
    int vetor[10] = {7, 2, 9, 4, 0, 6, 1, 8, 3, 5}; //Vetor desordenado

    printf("x antes do fork(): %d\n", x); // O valor de x é 1 antes do fork().
    
    printf("Vetor antes do fork(): { ");
    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    printf("} -->  Com endereço: 0x%lX\n\n", vetor);
    
    pid = fork(); //Ao fazer o fork, o processo é duplicado, e ambos os processos (pai e filho) continuam a execução a partir do ponto onde o fork foi chamado.

    

    if(pid != 0){ //Se for o processo pai, ele entre nesse bloco
        

        printf("\n========== Bloco do Pai ==========\n\n");

        printf("retorno do fork() neste processo: %d\n", pid);

        myPid = getpid(); 

        printf("pid processo PAI: %d\n", myPid);

        printf("Esperando o processo filho terminar...\n\n");
        waitpid(pid, &status, 0); 
        
        printf("\nProcesso filho terminou. Posso continuar\n\n");

        printf("x no pai após o waitpid(): %d\n\n", x); // O valor de x no processo pai permanece 1, pois o fork() cria uma cópia do processo, e as alterações feitas no processo filho não afetam o processo pai.

        printf("Vetor no pai após o waitpid(): { ");
        for(int i = 0; i < 10; i++){
            printf("%d ", vetor[i]);
        }
        printf("} --> Com endereço: 0x%lX \n\n", vetor); // O endereço do vetor no processo pai, visualmente, é o mesmo do endereço do vetor no processo filho, pois o fork() cria uma cópia do processo, e cada processo tem seu próprio espaço de memória. Ou seja, eles visualemnte são os mesmos endereços, mas são pilhas diferentes
        //Ou seja: Aqui ele printa de forma desordenada, pois o processo pai não tem acesso às alterações feitas no vetor do processo filho, e vice-versa.


        printf("Return que recebi do filho COM WEXITSTATUS: %d\n", WEXITSTATUS(status));
        printf("Return que recebi do filho SEM WEXITSTATUS: %d\n", status); 


        printf("========== Bloco do Pai (Fim) ==========\n\n");

    } else {


        printf("\n========== Bloco do Filho ==========\n\n");

        printf("retorno do fork() neste processo: %d\n", pid);

        myPid = getpid(); //getpid() é uma função que retorna o PID do processo atual, ou seja, o processo filho.
        printf("pid processo, FILHO: %d\n", myPid); // Repare que o processo filho é diferente do PID do pai, provavelmente maior
        
        x = 5; // O valor de x é alterado para 5 no processo filho
        printf("x no filho antes do exit(): %d\n", x); // O valor de x é 5 no processo filho antes do exit().

        quickSort(vetor, 0, 9);  // low = 0, high = 9 (vetor já é um ponteiro para endereço por isso não passa o endereço '&')


        printf("Vetor NO FILHO antes do exit(): { ");
        for(int i = 0; i < 10; i++){
            printf("%d ", vetor[i]);
        }
        printf("} -> Com endereço: 0x%lX \n\n", vetor); // O endereço do vetor no processo filho, visualmente, é o mesmo do endereço do vetor no processo pai, pois o fork() cria uma cópia do processo, e cada processo tem seu próprio espaço de memória. Ou seja, eles visualemnte são os mesmos endereços, mas são pilhas diferentes
        //Ou seja: Aqui ele printa de fomra ordenada



        
        printf("========== Bloco do Filho (Fim) ==========\n\n");
        exit(1);
    }
    return 0;
}