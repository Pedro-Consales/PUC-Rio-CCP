/*

#include <stdio.h>

int nums[4] = {65, -105, 111, 34};

int main (void) {
  
  int i;
  int s;
  s = 0

  for (i=0; i<4 ;i++)
    
    temp = s+nums[i];
    s = temp;

  printf ("soma = %d\n", s);

  return 0;
}

*/



.data
nums: .int 65, -105, 111, 34
Sf:  .string "Soma = %d\n"    /* string de formato para printf */

.text
.globl main
main:


/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/


movl  $0, %ebx  /* ebx = 0; int i*/
movq  $nums, %r12  /* r12 = &nums */
movl  $0, %ecx  /* ecx = 0; */


LOOP:
    cmpl $4, %ebx
    jge BREAK_LOOP #pule, se maior ou igual

    movq  %r12, %r13    /* copia endereço base para r13 para manter o ponteiro para o primeiro*/
    movl  $4, %edx      /* edx = 4 (tamanho de int) */
    imull  %ebx, %edx   /* edx = 4 * i */
    movslq %edx, %rdx   /* estende edx para 64 bits em rdx */
    addq  %rdx, %r13    /* r13 = endereço base + 4*i */
    addl  (%r13), %ecx  /* soma o valor de nums[i] ao acumulador */
    addl  $1, %ebx      /* i++ */
    jmp   L1            /* repete o loop */



BREAK_LOOP:
     movl  %ecx, %eax    /* eax = ecx (eax recebe o valor da soma) */


movl  %ecx, %eax    /* move soma para eax (para printf) */
movq  $Sf, %rdi     /* ponteiro para string de formato */
movl  %eax, %esi    /* valor a imprimir */
call  printf        /* imprime soma */

movq  $0, %rax 
movq  -8(%rbp), %rbx
movq  -16(%rbp), %r12
leave
ret
