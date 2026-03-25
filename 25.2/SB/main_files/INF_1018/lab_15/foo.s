/* 
float foo (double a, float b) {
  return (a+b)*(a-b);
}
*/


.text
.globl foo

/*

Dicionário
Reg     Var
%xmm0   a
%xmm1   b

*/

foo:
    push %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    

    /*Pego o que é float aumento para double*/
    cvtss2sd %xmm1, %xmm1
    movsd %xmm0, %xmm2 /* %xmm2 = buff_a */
    addsd %xmm1, %xmm0 /* a = a + b */
    subsd %xmm1, %xmm2 /* buff_a = a - b */
    mulsd %xmm2, %xmm0 /* valor de retorno tem que ser em %xmm0 */

    /* atenção que a função retorna um float, preciso retornar para float */

    cvtsd2ss %xmm0, %xmm0
    leave
    ret
