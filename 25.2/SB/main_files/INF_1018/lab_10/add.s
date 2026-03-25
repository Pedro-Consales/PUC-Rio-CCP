/*

struct X {
  int val;
  struct X *next;
};

int add (struct X *x) {
  int a = 0;
  //for (; x != NULL; x = x->next)
  while(x!=NULL)
  {
    valx = x->val;
    a += valx;
    x = x->prox
  }

  return a;
}


*/



/*
Dicionário

Reg     Var
ebx     a - CS
rdi     Struct X 
r15     buffx = struct x - CS
r12d    valx = x->val - CS
r13     &prox - CS



*/

.text
.globl add


add:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp

    /*Devo guardar o registradores callee-saved*/
    movq %rbx, -8(%rbp)
    movq %r15, -16(%rbp)
    movq %r12, -24(%rbp)
    movq %r13, -32(%rbp)



    movl $0, %ebx /*a = 0*/
    movq %rdi, %r15 /* r15 = x*/

    loop:
        cmpq $0, %r15 /* x == 0 */
        je fora_loop

        movl (%r15), %r12d /*r12d = x->val*/
        addl %r12d, %ebx /*ebx = ebx + r12d*/
        addq $8, %r15 /* Ando a quantidade necesária para o próximo endereço */
        movq (%r15), %r13 /* O conteúdo do próximo endereço é um entedereço */
        movq %r13, %r15 /* Guardo o endereço no r15 para continuar indo para os próximos */

        jmp loop



    fora_loop:
            movl %ebx, %eax

            movq -8(%rbp), %rbx
            movq -16(%rbp), %r15
            movq -24(%rbp), %r12
            movq -32(%rbp), %r13 



            leave
            ret
