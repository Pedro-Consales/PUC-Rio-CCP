/*

// int bemboba (int num) {
//   int local[4];
//   int *a;
//   int i;

//   for (i=0,a=local;i<4;i++) {
//     *a = num;
//     a++;
//   }
//   return addl (local, 4);
// }

*/

.text
.globl bemboba




bemboba:

        pushq %rbp
        movq %rsp, %rbp
        subq $40, %rsp


        /*Aqui devo abrir espaço para o meu RA*/
        movq %rbx, -24(%rbp)
        movq %r12, -32(%rbp)
        movq %r13, -40(%rbp)



        movl $0, %ebx
        leaq -16(%rbp), %r12
        movq %r12, %r13 /* r12 aponta para local */



        loop:
             cmpl $4, %ebx
             jge fora_loop 

             movl %edi, (%r13)
             addq $4, %r13

             incl %ebx

             jmp loop   



        fora_loop:        

                  movq %r12, %rdi
                  movl $4, %esi
                  call addl

                  /*Aqui devo restaurar o RA*/                      
                    movq -24(%rbp), %rbx 
                    movq -32(%rbp), %r12 
                    movq -40(%rbp), %r13  

                  leave
                  ret      