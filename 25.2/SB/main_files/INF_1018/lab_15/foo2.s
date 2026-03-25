/*
double foo2 (float a, float b) {
  return sin(a) + cos(b);
}
*/

.text
.globl foo1


/*
Dicionário

Reg     Var     tipo
%xmm0   a       float
%xmm1   b       float

*/

foo1:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    /*veja que a é float é passado como parmâmetro para o sen que tem cabeçalo como double sin(double a), ou seja, tenho que converter o parâmetro para double*/

    cvtss2sd %xmm0, %xmm0 /* (double)a */
    movss %xmm1, -4(%rbp) /* Guardo o b antes do call para ele não ser perdido*/ 
    call sin

    /*Agora que eu passei o %xmm0 como parâmetro, ele é retornado como o valor da função e eu preciso guardar ele*/

    movsd %xmm0, -12(%rbp) /* guardo o valor de retorno do sin(a) no RA */
    
    /*Vou fazer a soma mas preciso aumentar o float b para double também, pois vou passar no cos(b)*/
   
    movss -4(%rbp), %xmm1 /* Resgato o %xmm1 = b que se perdeu depois do call sin(a)*/

    cvtss2sd %xmm1, %xmm1 /* converto b para double */

    movsd %xmm1, %xmm0 /* mando b para o registrador que tava o valor de a para passar como parâmetro*/

    call cos

    addsd -12(%rbp), %xmm0

    cvtsd2ss %xmm0, %xmm0


    leave
    ret


    
