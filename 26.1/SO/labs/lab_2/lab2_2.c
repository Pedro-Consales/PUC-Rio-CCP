#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(void){
    char buff[100];

    printf("digite a mensagem do dia:\n-");

    fgets(buff, sizeof(buff), stdin);

    int segmento, chave = 8752;
    char *msg;

    segmento = shmget(chave, sizeof(buff), IPC_CREAT | S_IWUSR);

    msg = shmat(segmento, 0, 0);

    strcpy(msg, buff);

    printf("mensagem do dia salva em chave %d\n", chave);
    return 0;
}




// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <sys/stat.h>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <stdio.h>

// int main(void){
//     int segmento, chave = 8752;
//     char *msg;

//     segmento = shmget(chave, sizeof(char) * 30, S_IRUSR);

//     msg = shmat(segmento, 0, 0);

//     printf("Mensagem do dia:\n%s", msg);
    
//     return 0;
// }