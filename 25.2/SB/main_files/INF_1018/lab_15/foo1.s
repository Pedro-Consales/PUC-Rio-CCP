/*
float foo1 (float a, float b) {
  return sin(a) + b;
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

    /*veja que a é floate é passado como parmâmetro para o sen que tem cabeçalo como double sin(double a), ou seja, tenho que converter o parâmetro para double*/

    cvtss2sd %xmm0, %xmm0
    movss %xmm1, -4(%rbp) /* Guardo o b antes do call para ele não ser perdido*/ 
    call sin
    /*Agora que eu passei o %xmm0 como parâmetro, ele é retornado como o valor da função*/
    


    /*Vou fazer a soma mas preciso aumentar o float b para double também, a final o retorno de sin é um double*/
    movss -4(%rbp), %xmm1 /* Resgato o %xmm1 que se perdeu depois do call*/
    cvtss2sd %xmm1, %xmm1

    addsd %xmm1, %xmm0

    cvtsd2ss %xmm0, %xmm0


    leave
    ret


    