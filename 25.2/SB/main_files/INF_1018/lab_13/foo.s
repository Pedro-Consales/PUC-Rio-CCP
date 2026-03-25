/*

int foo (int x) {
  return x+1;
}

*/



.text
.globl foo

foo:
    pushq %rbp
    movq %rsp, %rbp
    /*Não precisa abrir espaço pro RA*/
    incl %edi
    movl %edi, %eax
    
    leave
    ret
