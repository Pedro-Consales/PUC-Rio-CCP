/*
int nums[] = {10, -21, -30, 45};
int main() {
  int i, *p;
  for (i = 0, p = nums; i != 4; i++, p++)
    printf("%d\n", *p);
  return 0;
}
*/

.data
nums:  .int  10, -21, -30, 45
Sf:  .string "%d\n"    /* string de formato para printf */

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/********************************************************/

/* for (i = 0, p = nums; i != 4; i++, p++) */
/* i = 0 */
/* p = nums */

/* while i != 4 */
/* i++ */
/* p++ */

  movl  $0, %ebx  /* ebx = 0; 0 é um numero inteiro de 4 bytes = 32 bits, então eu pego o 0 e guardo no registrador de 32bits */
  movq  $nums, %r12  /* r12 = &nums; movQ pega o endereçodo primeiro elemento do vetor e guarda com 8 bytes no regsitrador r12 */

L1:
  cmpl  $4, %ebx  /* compara ebx com 4 (a comparação ainda não sabemos, é definida na linha seguinte) */
  je  L2          /* goto L2; o que ta sendo comparado antes -> je = jump (if) equal para L2 e executa o bloco L2. */

  /* Se L2 Falso conitnua linha a linha, se não, vai para o fim do código. */
  /* Nesse caso como estamos fazendo um for, o if é para encerrar qunado o loop atinge a quantidade máxima */

  /* Se falso, continua loop */
  movl  (%r12), %eax    /* eax = *r12; (%r12) -> pega o conteúdo do que r12 guarda (endereço do primeiro elemento de nums) 
                           movl -> mova para %eax (registrador de 4bytes = 32 bits) esse valor
                           logo em eax vamos ter o valor do priemiro elemento do vetor no i = 0 -> vetor[i] */
/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */ 
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro); quem é Sf? */
  movl    %eax, %esi   /* segundo parametro  (inteiro); eax é o conteúdo do vetor[i] e guardo esse conteúdo no registrador de 8bytes esi */
  call  printf         /* chama a funcao da biblioteca; por que printamos eax e não o conteúdo do potneiro? Pois no print o registrador é destruido, então tecnicamente eax funciona com uma epécie de buffer */
/*************************************************************/

  addl  $1, %ebx  /* ebx += 1; incrementa 1 ao ebx que é o contador */
  addq  $4, %r12  /* r12 += 4; anda uma casa do vetor + 4 bytes na memória */
  jmp  L1         /* goto L1; Volta o loop */

L2:  
/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret      
/***************************************************************/
