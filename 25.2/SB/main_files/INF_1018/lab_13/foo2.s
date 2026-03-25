/*
int foo (int x) {
  return add(x);
}
*/



.text
.globl foo

foo:
    pushq %rbp
    movq %rsp, %rbp
    /*Não precisa abrir espaço pro RA*/
    /*edi já é o parâmetro do foo que passo pro add também*/
    call add
    
    leave
    ret