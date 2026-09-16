/*
 * prog1.c — Escreve dados em um arquivo mapeado na memória
 *
 * Fluxo:
 *   1. Cria/abre o arquivo compartilhado
 *   2. Define o tamanho do arquivo
 *   3. Mapeia o arquivo na memória com mmap()
 *   4. Escreve uma mensagem no ponteiro (= escreve no arquivo)
 *   5. Limpa o mapeamento
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>       /* open(), O_RDWR, O_CREAT */
#include <unistd.h>      /* ftruncate(), close() */
#include <sys/mman.h>    /* mmap(), munmap(), MAP_SHARED */
#include <sys/stat.h>

#define ARQUIVO   "compartilhado.bin"
#define TAMANHO   256   /* tamanho do arquivo em bytes */

int main() {

    /* ── 1. Cria o arquivo (ou abre se já existir) ── */
    int fd = open(ARQUIVO, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    /* ── 2. Define o tamanho do arquivo ──
     * O arquivo precisa ter tamanho > 0 para poder ser mapeado.
     * ftruncate() ajusta o tamanho sem precisar escrever nada. */
    if (ftruncate(fd, TAMANHO) == -1) {
        perror("ftruncate");
        exit(1);
    }

    /* ── 3. Mapeia o arquivo na memória ──
     *
     * NULL        → deixa o SO escolher o endereço
     * TAMANHO     → quantos bytes mapear
     * PROT_WRITE  → queremos escrever
     * MAP_SHARED  → mudanças refletem no arquivo real (e são vistas por outros processos)
     * fd          → descritor do arquivo
     * 0           → começar do início do arquivo
     *
     * Retorna um ponteiro que se comporta como um array de char. */
    char *ptr = mmap(NULL, TAMANHO, PROT_READ | PROT_WRITE,
                     MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    /* O fd pode ser fechado após o mmap — o mapeamento continua válido */
    close(fd);

    /* ── 4. Escreve a mensagem ──
     * Escrever em ptr é exatamente igual a escrever no arquivo. */
    const char *mensagem = "Ola prog2! Mensagem via mmap.";
    strncpy(ptr, mensagem, TAMANHO);

    printf("[prog1] Mensagem escrita no arquivo: \"%s\"\n", ptr);
    printf("[prog1] Agora execute ./prog2 para ler.\n");

    /* ── 5. Desfaz o mapeamento ──
     * msync() garante que tudo foi gravado no arquivo antes de sair. */
    msync(ptr, TAMANHO, MS_SYNC);
    munmap(ptr, TAMANHO);

    return 0;
}