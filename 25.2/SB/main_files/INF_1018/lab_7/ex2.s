
.data
S2:    .byte 65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0
Sf:  .string "%c"    /* primeira string de formato para printf */
Sf2: .string "\n"    /* segunda string de formato para printf */

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/

movq $S2, %r12 /*Guarda o endereço do primeiro elemento no registrador r12*/

LOOP:
    cmpb $0, (%r12)
    je QUEBRA_LOOP

    cmpb $123, (%r12)
    je SE_FALSO
    cmpb $125, (%r12)
    je SE_FALSO


    movsbl (%r12), %eax

    /*************************************************************/
    /* este trecho imprime o valor de %eax (estraga %eax)  */
    movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
    movl    %eax, %esi   /* segundo parametro  (inteiro) */
    movl  $0, %eax
    call  printf       /* chama a funcao da biblioteca */
    /*************************************************************/

    addq $1, %r12
    jmp LOOP



    SE_FALSO:
        addq $1, %r12
        jmp LOOP









QUEBRA_LOOP:
    /*************************************************************/
    /* este trecho imprime o \n (estraga %eax)  resulta no final do vetor */
    movq    $Sf2, %rdi    /* primeiro parametro (ponteiro)*/
    movl  $0, %eax
    call  printf       /* chama a funcao da biblioteca */
    /*************************************************************/

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
movq  $0, %rax  /* rax = 0  (valor de retorno) */
movq    -16(%rbp), %r12 /* recupera r12 */
movq    -8(%rbp), %rbx  /* recupera rbx */
leave
ret      
/***************************************************************/
