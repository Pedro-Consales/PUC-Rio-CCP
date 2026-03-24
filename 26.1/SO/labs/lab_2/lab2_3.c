// 3) Busca paralela em vetor 

// Faça um programa paralelo (com pelo menos 4 processos)
// para localizar uma chave em um vetor.

// Crie uma memória compartilhada com dados numéricos inteiros e desordenados e a divida
// pelo número de processos
// Cada processo deve procurar o dado na sua área
// de memória e informar a posição onde o dado foi
// localizado.

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    
    int segmento = shmget(IPC_PRIVATE, 40 * sizeof(int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR); 
    //Dividir em 4 processos, cada um com 10 posições
    //IPC_PRIVATE: Gera uma chave única para o segmento de memória compartilhada
    //40 * sizeof(int): Define o tamanho do segmento de memória compartilhada (40 inte
    //IPC_CRE: Cria um novo segmento de memória compartilhada
    //IPC_EXCL: Força falar se já existir memoria compartilhada
    //S_IRUSR | S_IWUSR: Define as permissões de leitura e escrita para o proprietário do segmento de memória compartilhada


    if(segmento == -1){
        perror("Erro ao criar segmento de memória compartilhada");
        return 1;
    }

    int* v = (int*) shmat(segmento, 0, 0);
    if(v == (int*) -1){
        perror("Erro ao anexar segmento de memória compartilhada");
        return 1;
    }

    v[0] = 5;
    v[1] = 2;
    v[2] = 8;
    v[3] = 8;
    v[4] = 2;
    v[5] = 6;
    v[6] = 7;
    v[7] = 7;
    v[8] = 9;
    v[9] = 9;
    v[10] = 8;
    v[11] = 7;
    v[12] = 6;
    v[13] = 5;
    v[14] = 10;
    v[15] = 5;
    v[16] = 2;
    v[17] = 3;
    v[18] = 1;
    v[19] = 4;
    v[20] = 6;
    v[21] = 11;
    v[22] = 12;
    v[23] = 13;
    v[24] = 14;
    v[25] = 15;
    v[26] = 16;
    v[27] = 17;
    v[28] = 18;
    v[29] = 19;
    v[30] = 20;
    v[31] = 21;
    v[32] = 22;
    v[33] = 23;
    v[34] = 24;
    v[35] = 25;
    v[36] = 26;
    v[37] = 27;
    v[38] = 28;
    v[39] = 29;
    

    int tamanho_vetor = 40;
    int qtd_processos = 4;
    int chave_a_ser_buscada = 6;
    int tam_bloco = tamanho_vetor / qtd_processos;

    int i;
    int status;
    for(i = 0; i < qtd_processos; i++){
        int pid = fork();

        if(pid == 0){

            int inicio = i * tam_bloco;
            int fim = inicio + (tam_bloco);

            printf("Aqui eh um processo filho %d\n", i+1 );
            printf("O PID desse processo é %d\n\n", getpid());
    
            printf("Vou chegar no intervalo de posicoes\n { %d --- %d }\n\n", inicio, fim);
    
            for(int j=inicio; j<fim; j++){
    
                printf("v[%d] = %d\n", j, v[j]);
                if (v[j] == chave_a_ser_buscada){
                    printf("Encontrei a chave!\n\n");
                }
    
            }
            exit(1); // Encerra o processo filho

        }


    }

    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
        

    for(int i = 0; i < qtd_processos; i++){
        wait(NULL);
    }

    return 0;
}


