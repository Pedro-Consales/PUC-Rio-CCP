/*
double foo3 (double *a, int n) {
  int i = 0;
  double r = 0.0;
  //for (i=0; i<n; i++) 
  while(i<n){

        double resp = sin(*a);
        r += resp;
        a++;
        i++;
    }
  return r;
}
*/



.text 
.globl foo3


/*
Dicionário

Reg     Var
%rdi    double *a ->  Nesse caso é rdi pq é um ponteiro
%esi    int n
r10d    int i
r11d    int r
%xmm3   double r

*/

foo3:

    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp

    /* Aqui devo salvar os callee-saved */

    /* Não precisou */


    movl $0, %r10d        /* i = 0 */
    movl $0, %r11d       /* guardo o 0 no valor de inteiro e depois converto esse inteiro para double */
    cvtsi2sd %r11d, %xmm3 /* não é possível simplesmente mover uma constante para o registrador %xmm#, por isso temos que guardar em um reg normal e depois converter seu tipo */

    loop:

        cmpl %esi, %r10d
        jge fora_loop

            movl %esi, -24(%rbp)
            movl %r10d, -20(%rbp)
            movq %rdi, -16(%rbp) /* rdi = Endereço do ponteiro -> Aqui eu guardo o primerio parâmetro para não perder dps do call */
            movsd %xmm3, -8(%rbp) /* double r -> gaurdar o xmm3 para pegar deposi do call*/
            movsd (%rdi), %xmm0   /* conteúdo do endereço apontado pelo rdi vai ficar guardado no xmm0 */
            call sin

            movsd -8(%rbp), %xmm3 /* resgato o valor do double */
            addsd %xmm0, %xmm3 /* r = sen + r */

            movq -16(%rbp), %rdi
            addq $8, %rdi

            movl -20(%rbp), %r10d
            incl %r10d

            movl -24(%rbp), %esi

            jmp loop

    fora_loop:

        movsd %xmm3, %xmm0

        leave
        ret


