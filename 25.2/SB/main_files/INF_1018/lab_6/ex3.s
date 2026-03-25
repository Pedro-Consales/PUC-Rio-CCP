/*
int nums[] = {10, -21, -30, 45};
int main() {
  int i, *p;
  for (i = 0, p = nums; i != 4; i++, p++)
    if ((*p % 2) == 0)
      printf("%d\n", *p);
  return 0;
}
*/

/*
Fazer simplificação do código


int nums[] = {10, -21, -30, 45};

int main(void) {
  int i = 0;
  int *p = nums;

  while (i < 4) {
    if ((*p % 2) == 0) {
      printf("%d\n", *p);
    }
    i++;
    p++;
  }
  return 0;
}

*/


.data
nums:  .int  10, -21, -30, 45
Sf:  .string "%d\n"    /* string de formato para printf */

.text
.globl  main
main:

/*prólogo*/
pushq   %rbp        /* salva o valor antigo de %rbp na pilha          */
movq    %rsp, %rbp  /* cria um novo frame base: %rbp = %rsp           */
subq    $16, %rsp   /* reserva 16 bytes no stack frame da função      */
movq    %rbx, -8(%rbp)   /* salva o valor de %rbx em variavel local   */
movq    %r12, -16(%rbp)  /* salva o valor de %r12 em variavel local   */




movl $0, %ebx /*i=0*/
movq $nums, %r12 /*guardador do erndereço do primeiro elemento*/

loop:

    cmpl $4, %ebx
    jge break 

    movl (%r12), %eax
    movl %eax, %ecx
    and $0x01, %ecx

    cmpl $0, %ecx
    jne              /* ((*p % 2) == 0) */
    
    /* printf("%d\n", *p); */
    movl   (%r12), %esi    # carrega *p em %esi (segundo argumento)
    movq   $Sf, %rdi       # primeiro argumento = endereço da string "%d\n"
    xor    %eax, %eax      # limpa %eax
    call   printf

    notcond:
          

    addl $1, %ebx
    addq $4, %r12
    jmp loop



break:

      /* retorno 0 + epílogo */
      movl   $0, %eax    # return 0
      movq   -8(%rbp), %rbx
      movq   -16(%rbp), %r12
      leave
      ret
