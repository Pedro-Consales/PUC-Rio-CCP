/*

int filtro(int x, int lim) 
{
  if (x < lim)
    return 0;
  else
    return x;
}

*/


/*

#include <stdio.h>
#define LIM 1

int filtro(int x, int lim);

int nums[5] = {3,-5,7,8,-2};

int main() {
  int i;
  int *p;
  p = nums;
  for (i = 0; i < 5; i++) {
    int temp = filtro(*p,LIM));
    printf("%d\n", temp);
    p++;
  }
  return 0;

*/

  .data
  nums: .int 3, -5, 7, 8, -2
  s1:   .string "Numero %d\n"

  .text
  .globl main
  main:
  /* prologo */
     pushq %rbp
     movq  %rsp, %rbp
     subq  $16, %rsp
     movq  %rbx, -8(%rbp)
     movq  %r12, -16(%rbp)

  /* coloque seu codigo aqui */
  movl $0, %ebx
  movq $nums, %r12

  loop:
      cmpl $5, %ebx
      jge ENCERRA_LOOP


      movl (%r12), %edi /*(1o parametro) guardo o conteúdo o endereço que está armazenado em r12*/
      movl $1, %esi /* (2o parametro) DEFINE LIM = 1 */
      call filtro /* Chama a função*/
    

      movq $s1, %rdi /* (1o parâmetro) passa o formato da sring do printf */
      movl %eax, %esi /* Como o valor de retonro é guardado no %eax, passo o eax como esi para parametro */
      movl $0, %eax /* Condição especial do printf, estraga eax*/
      call printf/* chama função */

      addq $4, %r12
      incl %ebx
      jmp loop


    ENCERRA_LOOP:
      /* finalizacao */
      movq -8(%rbp), %rbx
      movq -16(%rbp), %r12
      leave
      ret


    filtro:  
      
      cmpl %esi, %edi
      jge SE_FALSE

      movl $0, %eax
      ret

      SE_FALSE:
        movl %edi, %eax 
        ret
  

  
