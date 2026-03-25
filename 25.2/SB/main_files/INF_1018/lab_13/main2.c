#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>

// Macros do enunciado:
#define PAGE_START(P) ((intptr_t)(P) & ~((pagesize)-1))
#define PAGE_END(P)   (((intptr_t)(P) + (pagesize) - 1) & ~((pagesize)-1))

int execpage(void *ptr, size_t len) {
    const long pagesize = sysconf(_SC_PAGE_SIZE);
    if (pagesize == -1) return -1;

    void *start = (void *)PAGE_START(ptr);
    size_t size = (size_t)((char *)((void *)PAGE_END((intptr_t)ptr + len)) - (char *)start);

    if (mprotect(start, size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return -1; // use errno para diagnosticar (EPERM, EINVAL, etc.)
    }
    return 0;
}
#undef PAGE_START
#undef PAGE_END

int add (int x) {
  return x+1;
}


typedef int (*funcp)(int x);

int main(void) {


    // Seu código:
    unsigned char codigo[] = {
        0x55,                        // push   %rbp
        0x48, 0x89, 0xe5,            // mov    %rsp,%rbp
        0xe8, 0x00, 0x00, 0x00, 0x00, // call   9 <foo+0x9>
        0xc9,                        // leave
        0xc3                         // ret
    };



    // 1) Tornar a(s) página(s) que contêm 'codigo' executáveis
    if (execpage(codigo, sizeof codigo) != 0) {
        perror("execpage/mprotect");
        return 1;
    }

    // 2) Chamar o buffer como função
    funcp f = (funcp)codigo;
    int i = f(10);   // incrementa 10 → 11
    printf("O valor de i é %d\n", i);
    return 0;
}
