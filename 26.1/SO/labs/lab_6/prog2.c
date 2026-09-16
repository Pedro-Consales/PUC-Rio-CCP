
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>    
#include <sys/stat.h>    

#define ARQUIVO   "compartilhado.bin"

int main() {


    int fd = open(ARQUIVO, O_RDONLY);
    if (fd == -1) {
        perror("open deu erro, rode o prog1 antes!");
        exit(1);
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        exit(1);
    }
    size_t tamanho = st.st_size;


    char *ptr = mmap(NULL, tamanho, PROT_READ,
                     MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    close(fd);  


    printf("[prog2] Mensagem lida do arquivo: \"%s\"\n", ptr);


    munmap(ptr, tamanho);

    return 0;
}