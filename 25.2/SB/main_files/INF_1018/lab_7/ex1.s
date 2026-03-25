/*
char S2[] = {65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0};
int main (void) {
  //char *pc = S2;
  char *pc;
  pc = S2;
  //while (*pc)
  while(*pc != 0)
    //printf ("%c", *pc++);
    printf(%c, *pc);
    *pc++;
  printf("\n");
  return 0;
}
*/

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

movq  $S2, %r12  /* r12 = &S2 -> Como S2 é um espaço de memória, r12 vai ser o registrador que guarda o endereço */

L1: /*loop*/
  cmpb  $0, (%r12)  /* if (*pc == 0) -> Comapra o conteúdo -> (%r12) com o valor zero, ultimo elemento do vetor  */
  je  L2          /* goto L2 (Jump if equal)  */

  movsbl  (%r12), %eax    /* eax = *r12 (registrando e estendendo -> (s) o byte(b) para 32 bits (l))p-*/

/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

  addq  $1, %r12  /* r12 += 1; ou incq %rbx??? */ 
  jmp  L1         /* goto L1; volta o loop*/

L2: 
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