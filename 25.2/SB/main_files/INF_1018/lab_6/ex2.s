  /*
  int nums[] = {10, -21, -30, 45};
  int main() {
    int i, *p;
    int sum = 0;
    for (i = 0, p = nums; i != 4; i++, p++)
      sum += *p;
    printf("%d\n", sum);
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
  movl $0, %ecx /*sum*/


  loop:
      cmpl $4, %ebx 
      je done

      movl (%r12), %eax
      addl %eax, %ecx

      addl $1, %ebx
      addq $4, %r12
      jmp loop


  done:
    /* printf("%d\n", sum); */
    movl  %ecx, %esi      /* 2º arg: sum (int) */
    movq  $Sf, %rdi       /* 1º arg: formato   */
    xor   %eax, %eax      /* %al = 0 (variádico) */
    call  printf

    /* retorno 0 + epílogo */
    movq  $0, %rax
    movq  -8(%rbp), %rbx
    movq  -16(%rbp), %r12
    leave
    ret

  /*
  Esse código faz EXATAMENTE a mesma cosia que o anteriro, a única diferença é que:

  Ele incializa um registrador a mais, para poder gaurdar a soma -> linha 31

  soma o veotr [i] com o ecx que -> ecx = exc + vetor[i] --> Linha 39

  é tencinamente eu fazer 
  0 = 0 + 10
  10 = 10 + -21


  e o print é feito fora do loop.

  O truque do loop aqui é começar ele e fazer uma condição, se for igual muda para outro segmaento para o loop e nesse segmento printa e para o programa

  tipo um 
  while(True):
      if condicao:
          break;
      acao1
      acao2
  ...

  print

  */