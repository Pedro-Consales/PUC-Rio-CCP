/*
 * prog1.c — Escreve dados em um arquivo mapeado na memória
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>       
#include <unistd.h>      
#include <sys/mman.h>    
#include <sys/stat.h>

#define ARQUIVO   "compartilhado.bin"
#define TAMANHO   256

int main() {


    int fd = open(ARQUIVO, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (ftruncate(fd, TAMANHO) == -1) {
        perror("ftruncate");
        exit(1);
    }


    char *ptr = mmap(NULL, TAMANHO, PROT_READ | PROT_WRITE,
                     MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }


    close(fd);


    const char *mensagem = "Ola prog2! Mensagem via mmap.";
    strncpy(ptr, mensagem, TAMANHO);

    printf("[prog1] Mensagem escrita no arquivo: \"%s\"\n", ptr);
    printf("[prog1] ./prog2 para ler.\n");


    msync(ptr, TAMANHO, MS_SYNC);
    munmap(ptr, TAMANHO);

    return 0;
}