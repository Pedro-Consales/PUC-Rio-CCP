/*

#include <stdio.h>


int main(void)
{

    int i, num;
    i = 0;
    num = 1;
    while (i < 10)
    {
        int quadrado;

        quadrado = num*num;
        printf("%d", quadrado);
        printf("\n");
        printf("\n");
        num++;
        i++;
    }
    

    return 0;
}

//Pensei em fazer calculando i*i, e rodando o while até 11, ou, quando fosse caluclar o quadrado, faria i+1.
//Mas acho que essa forma é a mais adequada, porém menos eficiente.

*/




.data
Sf:  .string "%d\n"    /* string de formato para printf */

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


movl $0, %ebx
movl $1, %r12d

LOOP:
    cmpl $10, %ebx /*ebx com 10*/
    jge FIM_LOOP /* Pule se maior*/

    movl %r12d, %eax /* eax = r12d */
    imull %r12d, %eax /* eax = r12d *//* eax = eax * r12d*/


    /* printf("%d\n", quadrado);  supõe quadrado já em %eax */
    movl   %eax, %esi        # 2º argumento: inteiro
    movq   $Sf, %rdi         # 1º argumento: ponteiro para "%d\n"
    xorl   %eax, %eax        # zerar %eax (chamada variádica)
    call   printf


    addl $1, %r12d
    addl $1, %ebx
    jmp LOOP

FIM_LOOP:


/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
movq  $0, %rax  /* rax = 0  (valor de retorno) */
movq    -16(%rbp), %r12 /* recupera r12 */
movq    -8(%rbp), %rbx  /* recupera rbx */
leave
ret      
/***************************************************************/


